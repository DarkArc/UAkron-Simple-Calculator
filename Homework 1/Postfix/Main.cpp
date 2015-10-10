#include "lib/PostfixVisitor.hpp"

#include "../Parser/Parser.hpp"

#include <iostream>

using namespace PostfixLib;

int main() {
  std::cout << eval(parse(std::cin)) << std::endl;
  return 0;
}
