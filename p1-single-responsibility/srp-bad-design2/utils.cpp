/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "utils.hpp"

#include <iostream>

std::vector<std::string> ssplit(std::string &s, char delim) {
  std::stringstream ss(s);
  std::vector<std::string> res;
  for (std::string tok; std::getline(ss, tok, delim);) {
    res.push_back(tok);
  }
  return res;
}

void LogMessage(LogLevel level, std::string message) {
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