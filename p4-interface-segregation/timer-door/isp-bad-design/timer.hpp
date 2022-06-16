#ifndef TIMER_HPP_
#define TIMER_HPP_

/* (C) Nguyen Ba Ngoc 2022 */

#include <thread>

class TimerClient;

class Timer {
public:
  void Start(int timeout_secs, TimerClient *client);
  void Stop();

private:
  std::thread *thr = nullptr;
};

#endif  // TIMER_HPP_