#ifndef CONDIMENT_DECORATOR_HPP_
#define CONDIMENT_DECORATOR_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"
#include <iostream>

class CondimentDecorator: public Beverage {
public:
  std::string description() override {
    return beverage->description() + ", " + name;
  }

  double cost() override {
    return beverage->cost() + price;
  }

  CondimentDecorator(Beverage *b) {
    beverage = b;
  }

  ~CondimentDecorator() {
    delete beverage;
  }

protected:
  Beverage *beverage;
};

#endif  //