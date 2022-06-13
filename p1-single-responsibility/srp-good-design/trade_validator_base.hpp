#ifndef TRADE_VALIDATOR_BASE_HPP_
#define TRADE_VALIDATOR_BASE_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include <string>
#include <vector>

class TradeValidatorBase {
public:
  virtual bool Validate(std::vector<std::string> &fields, int line_count) = 0;
};

#endif  // TRADE_VALIDATOR_BASE_HPP_