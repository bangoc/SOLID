#ifndef SIMPLE_TRADE_MAPPER_HPP_
#define SIMPLE_TRADE_MAPPER_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "trade_mapper_base.hpp"

class SimpleTradeMapper: public TradeMapperBase {
public:
  TradeRecord *Map(std::vector<std::string> &fields) override {
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
private:
  const double k_lot_size = 10000;
};

#endif  // SIMPLE_TRADE_MAPPER_HPP_