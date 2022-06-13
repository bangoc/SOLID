#ifndef TRADE_STORAGE_BASE_HPP_
#define TRADE_STORAGE_BASE_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include <string>
#include <vector>

#include "trade_record.hpp"

class TradeStorageBase {
public:
  virtual void Persist(TradeRecordList&) = 0;
};

#endif  // TRADE_STORAGE_BASE_HPP_