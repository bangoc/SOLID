#ifndef PROJECT_HPP_
#define PROJECT_HPP_

#include "back_end_developer.hpp"
#include "front_end_developer.hpp"

#include <memory>
#include <vector>

class Project {
public:
  using Developers = std::vector<std::unique_ptr<Developer>>;
  explicit Project(Developers developers):
      developers_{std::move(developers)} {}

  void Deliver() {
    for (auto &developer: developers_) {
      developer->Develop();
    }
  }

private:
  Developers developers_;
};

#endif  // PROJECT_HPP_