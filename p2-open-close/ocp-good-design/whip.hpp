#ifndef WHIP_HPP_
#define WHIP_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "condiment_decorator.hpp"

class Whip: public CondimentDecorator {
public:
  Whip(Beverage *beverage): CondimentDecorator(beverage) {
    name = "Whip";
    price = 0.9;
  }
};

#endif  // WHIP_HPP_