#ifndef TIMED_DOOR_HPP_
#define TIMED_DOOR_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "door.hpp"
#include "simple_door_alarm.hpp"

#include <iostream>

class TimedDoor: public Door {
public:
  void Lock() override {
    std::cout << "Timed Door locked" << std::endl;
    is_open = false;
    alarm->StopTiming();
  }
  void Unlock() override {
    std::cout << "Timed Door unlocked" << std::endl;
    is_open = true;
    alarm->StartTiming(alarm_secs);
  }
  bool IsDoorOpen() override {
    return is_open;
  }
  TimedDoor() {
    alarm = new SimpleDoorAlarm(this);
  }
  ~TimedDoor() {
    delete alarm;
  }

private:
  TimerClient *alarm;
  bool is_open = true;
  const int alarm_secs = 5;
};

#endif  // TIMED_DOOR_HPP_