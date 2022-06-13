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
  void fly() override {
    std::cout << "!!! Don't call, can't fly" << std::endl;
  }
};

#endif  // RUBBER_DUCK_HPP_