#ifndef FLYABLE_DUCK_HPP_
#define FLYABLE_DUCK_HPP_

#include "duck.hpp"

class FlyableDuck: public Duck {
public:
  virtual void fly() = 0;
};

#endif  // FLYABLE_DUCK_HPP_