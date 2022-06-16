#ifndef TIMED_DOOR_HPP_
#define TIMED_DOOR_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "door.hpp"

#include <iostream>

class TimedDoor: public Door {
public:
  void Lock() override {
    std::cout << "Timed Door locked" << std::endl;
    is_open = false;
    StopTiming();
  }
  void Unlock() override {
    std::cout << "Timed Door unlocked" << std::endl;
    is_open = true;
    StartTiming(alarm_secs);
  }
  bool IsDoorOpen() override {
    return is_open;
  }
  void Timeout() override {
    if (is_open) {
      std::cout << "!!Attension! The Door is Open!"
                << std::endl;
    }
  }

private:
  bool is_open = true;
  const int alarm_secs = 5;
};

#endif  // TIMED_DOOR_HPP_