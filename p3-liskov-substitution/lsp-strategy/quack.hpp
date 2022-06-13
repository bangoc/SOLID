#ifndef QUACK_HPP_
#define QUACK_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "quack_action.hpp"

#include <iostream>

class Quack: public QuackAction {
public:
  void perform() override {
    std::cout << "Quack Quack Quack" << std::endl;
  }
};

#endif  // QUACK_HPP_