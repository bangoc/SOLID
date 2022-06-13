#ifndef MOCHA_HPP_
#define MOCHA_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "condiment_decorator.hpp"

class Mocha: public CondimentDecorator {
public:
  Mocha(Beverage *beverage): CondimentDecorator(beverage) {
    name = "Mocha";
    price = 0.8;
  }
};

#endif  // MOCHA_HPP_