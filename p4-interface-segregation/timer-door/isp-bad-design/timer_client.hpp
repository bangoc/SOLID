#ifndef TIMER_CLIENT_HPP_
#define TIMER_CLIENT_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include "timer.hpp"

class TimerClient {
public:
  virtual void Timeout() = 0;
  void StartTiming(int secs);
  void StopTiming();
private:
  Timer timer;
};

#endif  // TIMER_CLIENT_HPP_