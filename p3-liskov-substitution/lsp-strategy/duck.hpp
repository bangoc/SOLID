#ifndef DUCK_HPP_
#define DUCK_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "fly_action.hpp"
#include "quack_action.hpp"

#include <iostream>

class Duck {
public:
  virtual void display() = 0;

  void fly() {
    if (!fly_action) {
      std::cout << "!! fly action is not set" << std::endl;
      return;
    }
    fly_action->perform();
  }

  void quack() {
    if (!quack_action) {
      std::cout << "!! quack action is not set" << std::endl;
      return;
    }
    quack_action->perform();
  }

  Duck(FlyAction *_fly, QuackAction *_quack) {
    fly_action = _fly;
    quack_action = _quack;
  }

  virtual ~Duck() {
    delete fly_action;
    delete quack_action;
  }
protected:
  FlyAction *fly_action;
  QuackAction *quack_action;
};

#endif  // DUCK_HPP_