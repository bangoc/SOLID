#ifndef LOGGER_BASE_HPP_
#define LOGGER_BASE_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include <string>

enum LogLevel {
  INFO,
  WARN,
  ERROR
};

class LoggerBase {
public:
  virtual void LogMessage(LogLevel level, std::string message) = 0;
};

#endif  // LOGGER_BASE_HPP_