#ifndef TRADE_RECORD_HPP_
#define TRADE_RECORD_HPP_
/*
  (C) Nguyen Ba Ngoc 2022
*/

#include <memory>
#include <string>
#include <vector>

struct TradeRecord {
  TradeRecord() {}

  TradeRecord(std::string _source_currency,
      std::string _destination_currency,
      int _lots,
      double _price) {
    source_currency = _source_currency;
    destination_currency = _destination_currency;
    lots = _lots;
    price = _price;
  }
  std::string source_currency;
  std::string destination_currency;

  int lots;
  double price;
};

using TradeRecordList = std::vector<std::shared_ptr<TradeRecord>>;

#endif  // TRADE_PROCESSOR_HPP_