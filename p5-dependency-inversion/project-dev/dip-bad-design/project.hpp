#ifndef PROJECT_HPP_
#define PROJECT_HPP_

#include "back_end_developer.hpp"
#include "front_end_developer.hpp"

class Project {
public:
  void Deliver() {
    fed.DevelopFrontEnd();
    bed.DevelopBackEnd();
  }

private:
  FrontEndDeveloper fed;
  BackEndDeveloper bed;
};

#endif  // PROJECT_HPP_