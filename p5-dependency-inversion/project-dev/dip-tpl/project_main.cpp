/* (C) Nguyen Ba Ngoc 2022 */

#include "project.hpp"

int main() {
  auto fed = FrontEndDeveloper();
  auto bed = BackEndDeveloper();
  auto nva = BackEndDeveloper();
  Project<FrontEndDeveloper, BackEndDeveloper> prj{{fed, bed, nva}};
  prj.Deliver();
  return 0;
}