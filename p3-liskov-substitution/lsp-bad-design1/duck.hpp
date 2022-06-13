#ifndef DUCK_HPP_
#define DUCK_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

class Duck {
public:
  virtual void display() = 0;
  virtual void quack() = 0;
  virtual void fly() = 0;
};

#endif  // DUCK_HPP_