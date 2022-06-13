#ifndef SQUEAK_HPP_
#define SQUEAK_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "quack_action.hpp"

#include <iostream>

class Squeak: public QuackAction {
public:
  void perform() override {
    std::cout << "Squeak Squeak Squeak" << std::endl;
  }
};

#endif  // SQUEAK_HPP_