#ifndef TRADE_MAPPER_BASE_HPP_
#define TRADE_MAPPER_BASE_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "trade_record.hpp"

#include <string>
#include <vector>

class TradeMapperBase {
public:
  virtual TradeRecord *Map(std::vector<std::string> &fields) = 0;
};

#endif  // TRADE_MAPPER_BASE_HPP_