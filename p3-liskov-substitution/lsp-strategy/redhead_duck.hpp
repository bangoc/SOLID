#ifndef REDHEAD_DUCK_HPP_
#define REDHEAD_DUCK_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "duck.hpp"
#include "fly_with_wings.hpp"
#include "quack.hpp"

#include <iostream>

class RedHeadDuck: public Duck {
public:
  RedHeadDuck(): Duck(new FlyWithWings(), new Quack()) {
  }

  void display() override {
    std::cout << "This is a Red Head duck" << std::endl;
  }
};

#endif  // REDHEAD_DUCK_HPP_