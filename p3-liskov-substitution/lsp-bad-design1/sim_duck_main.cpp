/* (C) Nguyen Ba Ngoc 2022 */

#include "duck.hpp"
#include "mallard_duck.hpp"
#include "redhead_duck.hpp"
#include "rubber_duck.hpp"

#include <memory>
#include <vector>

int main() {
  std::vector<std::shared_ptr<Duck>> ducks;

  ducks.push_back(std::make_shared<MallardDuck>());
  ducks.push_back(std::make_shared<RubberDuck>());
  ducks.push_back(std::make_shared<RedHeadDuck>());

  for (auto d: ducks) {
    d->display();
    d->quack();
    d->fly();
  }
  return 0;
}