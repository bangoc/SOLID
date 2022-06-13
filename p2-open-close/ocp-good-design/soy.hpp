#ifndef SOY_HPP_
#define SOY_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "condiment_decorator.hpp"

class Soy: public CondimentDecorator {
public:
  Soy(Beverage *beverage): CondimentDecorator(beverage) {
    name = "Soy";
    price = 0.1;
  }
};

#endif  // SOY_HPP_