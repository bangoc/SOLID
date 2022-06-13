#ifndef RUBBER_DUCK_HPP_
#define RUBBER_DUCK_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "duck.hpp"

#include <iostream>

class RubberDuck: public Duck {
public:
  void display() override {
    std::cout << "This is a rubber duck" << std::endl;
  }
  void quack() override {
    std::cout << "Squeak squeak squeak" << std::endl;
  }
};

#endif  // RUBBER_DUCK_HPP_