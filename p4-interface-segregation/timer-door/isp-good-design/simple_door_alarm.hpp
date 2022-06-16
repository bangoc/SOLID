#ifndef SIMPLE_DOOR_ALARM_HPP_
#define SIMPLE_DOOR_ALARM_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "timer_client.hpp"

class SimpleDoorAlarm: public TimerClient {
public:
  void Timeout() override {
    if (door->IsDoorOpen()) {
      std::cout << "!!Attension! The Door is Open!"
                << std::endl;
    }
  }
  SimpleDoorAlarm(Door *d): door(d) {}
  ~SimpleDoorAlarm();

private:
  Door *door;
};

#endif  // SIMPLE_DOOR_ALARM_HPP_