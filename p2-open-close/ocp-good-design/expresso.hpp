#ifndef EXPRESSO_HPP_
#define EXPRESSO_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"

class Expresso: public Beverage {
public:
  Expresso() {
    name = "Expresso";
    price = 1.2;
  }
};

#endif  // EXPRESSO_HPP_