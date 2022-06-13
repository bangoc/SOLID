#ifndef FLY_WITH_WINGS_HPP_
#define FLY_WITH_WINGS_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "fly_action.hpp"

#include <iostream>

class FlyWithWings: public FlyAction {
public:
  void perform() override {
    std::cout << "Flying flap flap" << std::endl;
  }
};

#endif  // FLY_WITH_WINGS_HPP_