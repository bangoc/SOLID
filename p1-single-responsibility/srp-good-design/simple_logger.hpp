#ifndef SIMPLE_LOGGER_HPP_
#define SIMPLE_LOGGER_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "logger_base.hpp"

#include <iostream>

class SimpleLogger: public LoggerBase {
public:
  void LogMessage(LogLevel level, std::string message) override {
    switch (level) {
      case INFO:
        std::cout << "INFO";
        break;
      case WARN:
        std::cout << "WARN";
        break;
      case ERROR:
        std::cout << "ERROR";
        break;
    }
    std::cout << ": " << message << std::endl;
  }
};

#endif  // SIMPLE_LOGGER_HPP_