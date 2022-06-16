/* (C) Nguyen Ba Ngoc 2022 */

#include "original_door.hpp"
#include "timed_door.hpp"

#include <iostream>

int main() {
  TimedDoor timed_door;
  OriginalDoor original_door;
  Door *door = &timed_door;
  for (;;) {
    std::cout << "1. Lock" << std::endl
              << "2. Unlock" << std::endl
              << "3. Switch doors" << std::endl
              << "4. Exit" << std::endl
              << "Your command: ";
    int choice = 0;
    std::cin >> choice;
    switch (choice) {
      case 1:
        door->Lock();
        break;
      case 2:
        door->Unlock();
        break;
      case 3:
        if (door == &original_door) {
          door = &timed_door;
        } else {
          door = &original_door;
        }
        break;
      case 4:
        goto end;
      default:
        std::cout << "Unknown command" << std::endl;
    }
  }
  end:
  return 0;
}