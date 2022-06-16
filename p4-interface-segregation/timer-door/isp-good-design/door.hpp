#ifndef DOOR_HPP_
#define DOOR_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "timer_client.hpp"

class Door {
public:
  virtual void Lock() = 0;
  virtual void Unlock() = 0;
  virtual bool IsDoorOpen() = 0;
};

#endif  // DOOR_HPP_