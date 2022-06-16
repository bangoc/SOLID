/* (C) Nguyen Ba Ngoc 2022 */

#include "timer_client.hpp"

void TimerClient::StartTiming(int secs) {
  timer.Start(secs, this);
}
void TimerClient::StopTiming() {
  timer.Stop();
}
