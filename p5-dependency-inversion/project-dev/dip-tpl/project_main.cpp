/* (C) Nguyen Ba Ngoc 2022 */

#include "project.hpp"

int main() {
  auto fed = FrontEndDeveloper();
  auto bed = FrontEndDeveloper();
  Project<FrontEndDeveloper, BackEndDeveloper> prj{{fed, bed}};
  prj.Deliver();
  return 0;
}