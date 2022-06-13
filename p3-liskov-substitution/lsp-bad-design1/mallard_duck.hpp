#ifndef MALLARD_DUCK_HPP_
#define MALLARD_DUCK_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "duck.hpp"

#include <iostream>

class MallardDuck: public Duck {
public:
  void display() override {
    std::cout << "This is a Mallard duck" << std::endl;
  }
  void quack() override {
    std::cout << "Quack quack quack" << std::endl;
  }
  void fly() override {
    std::cout << "A Mallard duck is flying" << std::endl;
  }
};

#endif  // MALLARD_DUCK_HPP_