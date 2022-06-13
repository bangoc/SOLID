#ifndef TRADE_DATA_PROVIDER_BASE_HPP_
#define TRADE_DATA_PROVIDER_BASE_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include <iostream>
#include <string>
#include <vector>

class TradeDataProviderBase {
public:
  virtual std::vector<std::string> ReadTradeData() = 0;
};

#endif  // TRADE_DATA_PROVIDER_BASE_HPP_