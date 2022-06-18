#ifndef EXPRESSO_HPP_
#define EXPRESSO_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"

class Expresso: public Beverage {
public:
  double cost() override {
    return expresso_price + Beverage::cost();
  }
  std::string description() override {
    return std::string("Expresso") + Beverage::description();
  }
private:
  const double expresso_price = 1.2;
};

#endif  // EXPRESSO_HPP_