#ifndef BEVERAGE_HPP_
#define BEVERAGE_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include <string>

class Beverage {
public:
  std::string get_description() {
    return description;
  }
  virtual double cost() = 0;

protected:
  std::string description;
};

#endif  // BEVERAGE_HPP_