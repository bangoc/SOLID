#ifndef SIMPLE_TRADE_VALIDATOR_HPP_
#define SIMPLE_TRADE_VALIDATOR_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "logger_base.hpp"
#include "trade_validator_base.hpp"

#include <sstream>

class SimpleTradeValidator: public TradeValidatorBase {
public:
  SimpleTradeValidator(LoggerBase *_logger) :
        logger(_logger) {}
  bool Validate(std::vector<std::string> &fields, int line_count) override {
    if (fields.size() != 3) {
      std::stringstream msg;
      msg << "Line" << line_count << " malformed. " << "Only "
          << fields.size() << " field(s) found.";
      logger->LogMessage(WARN, msg.str());
      return false;
    }
    if (fields[0].length() != 6) {
      std::stringstream msg;
      msg << "Trade currencies on line " << line_count << " malformed: "
          << fields[0];
      logger->LogMessage(WARN, msg.str());
      return false;
    }
    std::stringstream ss{fields[1]};
    int trade_amount;
    if (!(ss >> trade_amount)) {
      std::stringstream msg;
      msg << "Trade amount on line " << line_count
          << " not a valid integer: " << fields[1];
      logger->LogMessage(WARN, msg.str());
      return false;
    }
    double trade_price;
    ss.clear();
    ss.str(fields[2]);
    if (!(ss >> trade_price)) {
      std::stringstream msg;
      msg << "Trade price on line " << line_count
          << " not a valid decimal: " << fields[2];
      logger->LogMessage(WARN, msg.str());
      return false;
    }
    return true;
  }
private:
  LoggerBase *logger;
};

#endif  // SIMPLE_TRADE_VALIDATOR_HPP_