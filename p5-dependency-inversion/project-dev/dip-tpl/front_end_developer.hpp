#ifndef FRONT_END_DEVELOPER_HPP_
#define FRONT_END_DEVELOPER_HPP_

#include <iostream>

class FrontEndDeveloper {
public:
  void Develop() {
    DevelopFrontEnd();
  }

  void DevelopFrontEnd() {
    std::cout << "Implement frontend parts" << std::endl;
  }
};

#endif  // FRONT_END_DEVELOPER_HPP_