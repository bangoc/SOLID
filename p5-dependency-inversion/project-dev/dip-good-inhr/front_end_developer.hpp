#ifndef FRONT_END_DEVELOPER_HPP_
#define FRONT_END_DEVELOPER_HPP_

#include "developer.hpp"

#include <iostream>

class FrontEndDeveloper: public Developer {
public:
  void Develop() override {
    DevelopFrontEnd();
  }

  void DevelopFrontEnd() {
    std::cout << "Implement frontend parts" << std::endl;
  }
};

#endif  // FRONT_END_DEVELOPER_HPP_