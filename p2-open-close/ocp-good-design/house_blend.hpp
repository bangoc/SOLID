#ifndef HOUSE_BLEND_HPP_
#define HOUSE_BLEND_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"

class HouseBlend: public Beverage {
public:
  HouseBlend() {
    name = "House Blend";
    price = 2.0;
  }
};

#endif  // HOUSE_BLEND_HPP_