#ifndef DECAF_WITH_SOY_HPP_
#define DECAF_WITH_SOY_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"

class DecafWithSoy: public Beverage {
public:
  DecafWithSoy() {
    description = "Decaf with Soy";
  }
  double cost() override {
    return 1.6;
  }
};

#endif  // DECAF_WITH_SOY_HPP_