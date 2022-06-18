#ifndef DECAF_HPP_
#define DECAF_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"

class Decaf: public Beverage {
public:
  double cost() override {
    return decaf_price + Beverage::cost();
  }
  std::string description() override {
    return std::string("Decaf") + Beverage::description();
  }
private:
  const double decaf_price = 1.5;
};

#endif  // DECAF_HPP_