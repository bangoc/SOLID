/*
  (C) Nguyen Ba Ngoc 2022
*/

#include "utils.hpp"

std::vector<std::string> ssplit(std::string &s, char delim) {
  std::stringstream ss(s);
  std::vector<std::string> res;
  for (std::string tok; std::getline(ss, tok, delim);) {
    res.push_back(tok);
  }
  return res;
}