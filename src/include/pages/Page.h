#pragma once
#include <string>

namespace SCLI {
class Page {
 private:
  std::string name;

 public:
  Page(const std::string &pageName) : name(pageName) {}

  std::string getName() const;
};
}  // namespace SCLI