/* (C) Nguyen Ba Ngoc 2022 */

#include "decaf_with_soy.hpp"
#include "expressor_with_whip_and_mocha.hpp"
#include "house_blend_with_milk_and_mocha.hpp"

#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::vector<std::shared_ptr<Beverage>> order;
  order.push_back(std::make_shared<DecafWithSoy>());
  order.push_back(std::make_shared<ExpressorWithWhipAndMocha>());
  order.push_back(std::make_shared<HouseBlendWithMilkAndMocha>());
  for (auto item: order) {
    std::cout << item->get_description() << ": "
              << item->cost() << std::endl;
  }
  return 0;
}
