/* (C) Nguyen Ba Ngoc 2022 */

#include "project.hpp"

int main() {
  Project::Developers developers;
  developers.push_back(std::make_unique<FrontEndDeveloper>());
  developers.push_back(std::make_unique<BackEndDeveloper>());

  Project prj(std::move(developers));
  prj.Deliver();
  return 0;
}