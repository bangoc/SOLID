#ifndef TRADE_PROCESSOR_HPP_
#define TRADE_PROCESSOR_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "trade_record.hpp"
#include "trade_data_provider_base.hpp"
#include "trade_parser_base.hpp"
#include "trade_storage_base.hpp"

#include <cstdarg>
#include <iostream>
#include <string>
#include <vector>
class TradeProcessor {
public:
  TradeProcessor(TradeDataProviderBase *_provider,
                 TradeParserBase *_parser,
                 TradeStorageBase *_storage) {
    provider = _provider;
    parser = _parser;
    storage = _storage;
  }
  void ProcessTrades() {
    std::vector<std::string> lines = provider->ReadTradeData();
    TradeRecordList trades = parser->Parse(lines);
    storage->Persist(trades);
  }
private:
  TradeDataProviderBase *provider;
  TradeParserBase *parser;
  TradeStorageBase *storage;
};

#endif  // TRADE_PROCESSOR_HPP_