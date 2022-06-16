#ifndef ORIGINAL_DOOR_HPP_
#define ORIGINAL_DOOR_HPP_

#include "door.hpp"

#include <iostream>

class OriginalDoor: public Door {
public:
  void Lock() override {
    std::cout << "Original Door locked" << std::endl;
    is_open = false;
  }
  void Unlock() override {
    std::cout << "Original Door unlocked" << std::endl;
    is_open = true;
  }
  bool IsDoorOpen() override {
    return is_open;
  }
  void Timeout() override {
    if (is_open) {
      std::cout << "Should not have timing" << std::endl;
    }
  }

private:
  bool is_open = true;
};

#endif  // ORIGINAL_DOOR_HPP_