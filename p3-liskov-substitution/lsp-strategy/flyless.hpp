#ifndef FLYLESS_HPP_
#define FLYLESS_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "fly_action.hpp"

#include <iostream>

class Flyless: public FlyAction {
public:
  void perform() override {
    std::cout << "<< No way >>" << std::endl;
  }
};

#endif  // FLYLESS_HPP_