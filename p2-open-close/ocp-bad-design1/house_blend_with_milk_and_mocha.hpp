#ifndef HOUSE_BLEND_WITH_MILD_AND_MOCHA_HPP_
#define HOUSE_BLEND_WITH_MILD_AND_MOCHA_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"

class HouseBlendWithMilkAndMocha: public Beverage {
public:
  HouseBlendWithMilkAndMocha() {
    description = "House Blend with Milk and Mocha";
  }
  double cost() override {
    return 2.95;
  }
};

#endif  // HOUSE_BLEND_WITH_MILD_AND_MOCHA_HPP_