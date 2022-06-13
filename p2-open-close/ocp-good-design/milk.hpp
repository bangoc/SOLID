#ifndef MILK_HPP_
#define MILK_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "condiment_decorator.hpp"

class Milk: public CondimentDecorator {
public:
  Milk(Beverage *beverage): CondimentDecorator(beverage) {
    name = "Milk";
    price = 0.15;
  }
};

#endif  // MILK_HPP_