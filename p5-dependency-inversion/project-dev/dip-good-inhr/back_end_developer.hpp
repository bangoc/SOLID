#ifndef BACK_END_DEVELOPER_HPP_
#define BACK_END_DEVELOPER_HPP_

#include "developer.hpp"

#include <iostream>

class BackEndDeveloper: public Developer {
public:
  void Develop() override {
    DevelopBackEnd();
  }

  void DevelopBackEnd() {
    std::cout << "Develop backend parts" << std::endl;
  }
};

#endif  // BACK_END_DEVELOPER_HPP_