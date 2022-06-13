#ifndef TRADE_PARSER_BASE_HPP_
#define TRADE_PARSER_BASE_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "trade_record.hpp"

#include <string>
#include <vector>

class TradeParserBase {
public:
  virtual TradeRecordList Parse(std::vector<std::string>&) = 0;
};

#endif  // TRADE_PARSER_BASE_HPP_