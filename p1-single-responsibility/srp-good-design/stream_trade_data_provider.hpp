#ifndef STREAM_TRADE_DATA_PROVIDER_HPP_
#define STREAM_TRADE_DATA_PROVIDER_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "trade_data_provider_base.hpp"

class StreamTradeDataProvider: public TradeDataProviderBase {
public:
  StreamTradeDataProvider(std::istream& _is): is(_is){
  }
  std::vector<std::string> ReadTradeData() override {
    std::vector<std::string> lines;
    for (std::string line; std::getline(is, line);) {
      lines.push_back(line);
    }
    return lines;
  }
private:
  std::istream &is;
};

#endif  // STREAM_TRADE_DATA_PROVIDER_HPP_