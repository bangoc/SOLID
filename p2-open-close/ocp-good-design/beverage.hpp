#ifndef BEVERAGE_HPP_
#define BEVERAGE_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include <string>

class Beverage {
public:
  virtual std::string description() {
    return name;
  }
  virtual double cost() {
    return price;
  }

  virtual ~Beverage() {}
protected:
  std::string name = "Unknown";
  double price = 0;
};

#endif  // BEVERAGE_HPP_