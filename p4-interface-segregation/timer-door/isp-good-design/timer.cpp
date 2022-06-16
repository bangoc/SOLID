/* (C) Nguyen Ba Ngoc 2022 */

#include "timer_client.hpp"

#include <chrono>
#include <thread>

/* TODO: There are concurrency problems that need to be solved */

void Timer::Start(int timeout_secs, TimerClient *client) {
  if (thr) {
    return;
  }

  thr = new std::thread([client, timeout_secs, this] () {
    std::this_thread::sleep_for(std::chrono::duration<int>(timeout_secs));
    client->Timeout();
    delete thr;
    thr = nullptr;
  });
  thr->detach();
}

void Timer::Stop() {
  if (thr) {
    delete thr;
    thr = nullptr;
  }
}