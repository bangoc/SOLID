#ifndef TRADE_PROCESSOR_HPP_
#define TRADE_PROCESSOR_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "fake-sql/mock.hpp"
#include "trade_record.hpp"
#include "utils.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>
class TradeProcessor {
public:
  void ProcessTrades(std::istream &is) {
    std::vector<std::string> lines;
    for (std::string line; std::getline(is, line);) {
      lines.push_back(line);
    }
    TradeRecordList trades;
    int line_count = 0;
    for (auto line: lines) {
      ++line_count;
      auto fields = ssplit(line, ',');
      if (fields.size() != 3) {
        std::cout << "WARN: Line" << line_count << " malformed. "
          << "Only " << fields.size() << " field(s) found." << std::endl;
        continue;
      }
      if (fields[0].length() != 6) {
        std::cout << "WARN: Trade currencies on line " << line_count
          << " malformed: " << fields[0] << std::endl;
        continue;
      }
      std::stringstream ss{fields[1]};
      int trade_amount;
      if (!(ss >> trade_amount)) {
        std::cout << "WARN: Trade amount on line " << line_count <<
          " not a valid integer: " << fields[1] << std::endl;
        continue;
      }
      double trade_price;
      ss.clear();
      ss.str(fields[2]);
      if (!(ss >> trade_price)) {
        std::cout << "WARN: Trade price on line " << line_count <<
          " not a valid decimal: " << fields[2] << std::endl;
        continue;
      }
      std::string source_currency_code = fields[0].substr(0, 3);
      std::string destination_currency_code = fields[0].substr(3, 3);
      std::shared_ptr<TradeRecord> trade = std::make_shared<TradeRecord>();
      trade->source_currency = source_currency_code;
      trade->destination_currency = destination_currency_code;
      trade->lots = trade_amount / k_lot_size;
      trade->price = trade_price;
      trades.push_back(trade);
    }
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
    std::cout << "INFO: " << trades.size() << " trades processed" << std::endl;
  }
private:
  static float k_lot_size;;
};

#endif  // TRADE_PROCESSOR_HPP_