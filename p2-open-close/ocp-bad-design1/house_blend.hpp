#ifndef HOUSE_BLEND_HPP_
#define HOUSE_BLEND_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"

class HouseBlend: public Beverage {
public:
  double cost() override {
    return house_blend_price + Beverage::cost();
  }
  std::string description() override {
    return std::string("House Blend") + Beverage::description();
  }
private:
  double house_blend_price = 2.0;
};

#endif  // HOUSE_BLEND_HPP_