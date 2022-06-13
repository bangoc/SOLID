#ifndef REDHEAD_DUCK_HPP_
#define REDHEAD_DUCK_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "duck.hpp"

#include <iostream>

class RedHeadDuck: public Duck {
public:
  void display() override {
    std::cout << "This is a Red Head duck" << std::endl;
  }
  void quack() override {
    std::cout << "Quack quack quack" << std::endl;
  }
  void fly() override {
    std::cout << "A Red Head duck is flying" << std::endl;
  }
};

#endif  // REDHEAD_DUCK_HPP_