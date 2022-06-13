#ifndef BEVERAGE_HPP_
#define BEVERAGE_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include <string>

class Beverage {
public:

  virtual std::string description() {
    std::string desc = "";
    if (has_milk()) {
      if (desc.length() > 0) {
        desc += std::string(", Milk");
      } else {
        desc += std::string(" with Milk");
      }
    }
    if (has_soy()) {
      if (desc.length() > 0) {
        desc += std::string(", Soy");
      } else {
        desc += std::string(" with Soy");
      }
    }
    if (has_mocha()) {
      if (desc.length() > 0) {
        desc += std::string(", Mocha");
      } else {
        desc += std::string(" with Mocha");
      }
    }
    if (has_whip()) {
      if (desc.length() > 0) {
        desc += std::string(", Whip");
      } else {
        desc += std::string(" with Whip");
      }
    }
    return desc;
  }

  virtual double cost() {
    double condiments = 0.0;
    condiments += has_milk() * milk_price
      + has_soy() * soy_price
      + has_mocha() * mocha_price
      + has_whip() * whip_price;
    return condiments;
  }

  bool has_milk() {
    return milk;
  }

  void set_milk(bool value) {
    milk = value;
  }

  bool has_soy() {
    return soy;
  }

  void set_soy(bool value) {
    soy = value;
  }

  bool has_mocha() {
    return mocha;
  }

  void set_mocha(bool value) {
    mocha = value;
  }

  bool has_whip() {
    return whip;
  }

  void set_whip(bool value) {
    whip = value;
  }

private:
  bool milk = false, soy = false, mocha = false, whip = false;
  double milk_price = 0.15,
         soy_price = 0.1,
         mocha_price = 0.8,
         whip_price = 0.9;
};

#endif  // BEVERAGE_HPP_