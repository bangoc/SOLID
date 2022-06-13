/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"
#include "milk.hpp"
#include "mocha.hpp"
#include "decaf.hpp"
#include "expresso.hpp"
#include "house_blend.hpp"
#include "soy.hpp"
#include "whip.hpp"

#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::vector<std::shared_ptr<Beverage>> order;

  order.push_back(std::shared_ptr<Soy>(
          new Soy(new Decaf())));
  order.push_back(std::shared_ptr<Mocha>(
          new Mocha(new Whip(new Expresso()))));
  order.push_back(std::shared_ptr<Mocha>(
          new Mocha(new Milk(new HouseBlend()))));

  for (auto item: order) {
    std::cout << item->description() << ": "
              << item->cost() << std::endl;
  }
  return 0;
}
