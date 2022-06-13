#ifndef SIMPLE_TRADE_PARSER_HPP_
#define SIMPLE_TRADE_PARSER_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "trade_parser_base.hpp"
#include "utils.hpp"

class SimpleTradeParser: public TradeParserBase {
public:
  SimpleTradeParser(TradeValidatorBase *_validator,
      TradeMapperBase *_mapper) {
    validator = _validator;
    mapper = _mapper;
  }
  TradeRecordList Parse(
        std::vector<std::string> &trade_data) override {
    TradeRecordList trades;
    int line_count = 0;
    for (auto line: trade_data) {
      ++line_count;
      auto fields = ssplit(line, ',');
      if (!validator->Validate(fields, line_count)) {
        continue;
      }
      TradeRecord *trade = mapper->Map(fields);
      trades.push_back(std::shared_ptr<TradeRecord>(trade));
    }
    return trades;
  }
private:
  TradeValidatorBase *validator;
  TradeMapperBase *mapper;
};

#endif  // SIMPLE_TRADE_PARSER_HPP_