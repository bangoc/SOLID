#ifndef SILENCE_HPP_
#define SILENCE_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "quack_action.hpp"

#include <iostream>

class Silence: public QuackAction {
public:
  void perform() override {
    std::cout << "<< Silence >>" << std::endl;
  }
};

#endif  // SILENCE_HPP_