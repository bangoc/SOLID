#ifndef PROJECT_HPP_
#define PROJECT_HPP_

#include "back_end_developer.hpp"
#include "front_end_developer.hpp"

#include <memory>
#include <variant>
#include <vector>

template <typename... Devs>
class Project {
public:
  using Developers = std::vector<std::variant<Devs...>>;

  explicit Project(Developers developers):
      developers_{std::move(developers)} {}

  void Deliver() {
    for (auto &developer: developers_) {
      std::visit([](auto &dev) { dev.Develop(); },
        developer);
    }
  }

private:
  Developers developers_;
};

#endif  // PROJECT_HPP_