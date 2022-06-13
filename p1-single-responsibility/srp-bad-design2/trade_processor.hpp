#ifndef TRADE_PROCESSOR_HPP_
#define TRADE_PROCESSOR_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "fake-sql/mock.hpp"
#include "trade_record.hpp"
#include "utils.hpp"

#include <cstdarg>
#include <iostream>
#include <string>
#include <vector>
class TradeProcessor {
public:
  void ProcessTrades(std::istream &is) {
    std::vector<std::string> lines = ReadTradeData(is);
    TradeRecordList trades = ParseTrades(lines);
    StoreTrades(trades);
  }

private:
  std::vector<std::string> ReadTradeData(std::istream &is) {
    std::vector<std::string> lines;
    for (std::string line; std::getline(is, line);) {
      lines.push_back(line);
    }
    return lines;
  }

  bool ValidateTradeData(std::vector<std::string> &fields, int line_count) {
    if (fields.size() != 3) {
      std::stringstream msg;
      msg << "Line" << line_count << " malformed. " << "Only "
          << fields.size() << " field(s) found.";
      LogMessage(WARN, msg.str());
      return false;
    }
    if (fields[0].length() != 6) {
      std::stringstream msg;
      msg << "Trade currencies on line " << line_count << " malformed: "
          << fields[0];
      LogMessage(WARN, msg.str());
      return false;
    }
    std::stringstream ss{fields[1]};
    int trade_amount;
    if (!(ss >> trade_amount)) {
      std::stringstream msg;
      msg << "Trade amount on line " << line_count
          << " not a valid integer: " << fields[1];
      LogMessage(WARN, msg.str());
      return false;
    }
    double trade_price;
    ss.clear();
    ss.str(fields[2]);
    if (!(ss >> trade_price)) {
      std::stringstream msg;
      msg << "Trade price on line " << line_count
          << " not a valid decimal: " << fields[2];
      LogMessage(WARN, msg.str());
      return false;
    }
    return true;
  }

  TradeRecord *MapTradeDataToTradeRecord(
        std::vector<std::string> &fields) {
    TradeRecord *trade = new TradeRecord();
    std::string source_currency_code = fields[0].substr(0, 3);
    std::string destination_currency_code = fields[0].substr(3, 3);
    trade->source_currency = source_currency_code;
    trade->destination_currency = destination_currency_code;
    std::stringstream ss{fields[1]};
    int trade_amount;
    ss >> trade_amount;
    trade->lots = trade_amount / k_lot_size;
    ss.clear();
    ss.str(fields[2]);
    ss >> trade->price;
    return trade;
  }

  TradeRecordList ParseTrades(
        std::vector<std::string> &trade_data) {
    TradeRecordList trades;
    int line_count = 0;
    for (auto line: trade_data) {
      ++line_count;
      auto fields = ssplit(line, ',');
      if (!ValidateTradeData(fields, line_count)) {
        continue;
      }
      TradeRecord *trade = MapTradeDataToTradeRecord(fields);
      trades.push_back(std::shared_ptr<TradeRecord>(trade));
    }
    return trades;
  }

  void StoreTrades(TradeRecordList &trades) {
    SqlConnection conn("DataSource=(local);"
      "Initial Catalog=TradeDatabase;Integrated Security=True");
    conn.Open();
    SqlTransaction *transaction = conn.BeginTransaction();
    for (auto trade: trades) {
      SqlCommand *command = conn.CreateCommand();
      command->transaction = transaction;
      command->command_type = SqlCommandType::StoredProcedure;
      command->command_text = "dbo.insert_trade";
      command->params.AddWithValue("@sourceCurrency", trade->source_currency);
      command->params.AddWithValue("@destinationCurrency", trade->destination_currency);
      command->params.AddWithValue("@lots", trade->lots);
      command->params.AddWithValue("@price", trade->price);
      command->ExecuteNonQuery();
    }
    transaction->Commit();
    conn.Close();
    std::stringstream msg;
    msg << trades.size() << " trades processed";
    LogMessage(INFO, msg.str());
  }

  static float k_lot_size;;
};

#endif  // TRADE_PROCESSOR_HPP_