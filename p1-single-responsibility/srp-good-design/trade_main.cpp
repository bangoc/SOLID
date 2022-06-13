/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "simple_logger.hpp"
#include "simple_trade_validator.hpp"
#include "simple_trade_mapper.hpp"
#include "simple_trade_parser.hpp"
#include "sql_trade_storage.hpp"
#include "stream_trade_data_provider.hpp"
#include "trade_processor.hpp"

int main() {
  SimpleLogger logger;
  SimpleTradeValidator validator(&logger);
  SimpleTradeMapper mapper;
  SimpleTradeParser parser(&validator, &mapper);
  StreamTradeDataProvider provider(std::cin);
  SqlTradeStorage storage(&logger);
  TradeProcessor trade((TradeDataProviderBase*)&provider,
      (TradeParserBase*)&parser, (TradeStorageBase*)&storage);
  trade.ProcessTrades();
  return 0;
}