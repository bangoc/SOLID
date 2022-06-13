#ifndef MALLARD_DUCK_HPP_
#define MALLARD_DUCK_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "duck.hpp"
#include "fly_with_wings.hpp"
#include "quack.hpp"

#include <iostream>

class MallardDuck: public Duck {
public:
  MallardDuck(): Duck(new FlyWithWings(), new Quack()) {
  }

  void display() override {
    std::cout << "This is a Mallard duck" << std::endl;
  }
};

#endif  // MALLARD_DUCK_HPP_