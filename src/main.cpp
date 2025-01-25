#include <iostream>

#include "classes/Page.h"

using namespace SCLI;

int main() {
  std::cout << "TEST" << std::endl;

  Page wow("AOIFJEUDIOKDLFH");

  std::cout << wow.getName();
  std::cin.get();
  return 0;
}