/* (C) Nguyen Ba Ngoc 2022 */

#include "beverage.hpp"
#include "decaf.hpp"
#include "expresso.hpp"
#include "house_blend.hpp"

#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::vector<std::shared_ptr<Beverage>> order;
  Decaf *decaf = new Decaf();
  decaf->set_soy(true);
  order.push_back(std::shared_ptr<Beverage>(decaf));

  Expresso *expresso = new Expresso();
  expresso->set_whip(true);
  expresso->set_mocha(true);
  order.push_back(std::shared_ptr<Beverage>(expresso));


  HouseBlend *hb = new HouseBlend();
  hb->set_milk(true);
  hb->set_mocha(true);
  order.push_back(std::shared_ptr<Beverage>(hb));
  for (auto item: order) {
    std::cout << item->description() << ": "
              << item->cost() << std::endl;
  }
  return 0;
}
