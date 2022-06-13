#ifndef DECAF_HPP_
#define DECAF_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"

class Decaf: public Beverage {
public:
  Decaf() {
    name = "Decaf";
    price = 1.5;
  }
};

#endif  // DECAF_HPP_