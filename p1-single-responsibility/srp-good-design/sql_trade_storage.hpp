#ifndef SQL_TRADE_STORAGE_HPP_
#define SQL_TRADE_STORAGE_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "fake-sql/mock.hpp"
#include "logger_base.hpp"
#include "trade_storage_base.hpp"

class SqlTradeStorage: public TradeStorageBase {
public:
  SqlTradeStorage(LoggerBase *_logger) {
    logger = _logger;
  }
  void Persist(TradeRecordList &trades) override {
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
    logger->LogMessage(INFO, msg.str());
  }
private:
  LoggerBase *logger;
};

#endif  // SQL_TRADE_STORAGE_HPP_