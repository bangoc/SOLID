#ifndef UTILS_HPP_
#define UTILS_HPP_

/*
  (C) Nguyen Ba Ngoc 2022
*/

#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> ssplit(std::string &s, char delim);

enum LogLevel {
  INFO,
  WARN,
  ERROR
};

void LogMessage(LogLevel level, std::string message);

#endif  // UTILS_HPP_