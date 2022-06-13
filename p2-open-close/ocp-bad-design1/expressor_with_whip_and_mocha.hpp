#ifndef EXPRESSOR_WITH_WHIP_AND_MOCHA_HPP_
#define EXPRESSOR_WITH_WHIP_AND_MOCHA_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"

class ExpressorWithWhipAndMocha: public Beverage {
public:
  ExpressorWithWhipAndMocha() {
    description = "Expressor with Whip and Mocha";
  }
  double cost() override {
    return 2.9;
  }
};

#endif  // EXPRESSOR_WITH_WHIP_AND_MOCHA_HPP_