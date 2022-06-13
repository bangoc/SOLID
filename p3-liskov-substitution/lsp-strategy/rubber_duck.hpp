#ifndef RUBBER_DUCK_HPP_
#define RUBBER_DUCK_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "duck.hpp"
#include "flyless.hpp"
#include "squeak.hpp"

#include <iostream>

class RubberDuck: public Duck {
public:
  RubberDuck(): Duck(new Flyless(), new Squeak()) {
  }

  void display() override {
    std::cout << "This is a rubber duck" << std::endl;
  }
};

#endif  // RUBBER_DUCK_HPP_