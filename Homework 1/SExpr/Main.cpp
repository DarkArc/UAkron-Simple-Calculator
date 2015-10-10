#include "lib/SExprVisitor.hpp"

#include "../Parser/Parser.hpp"

#include <iostream>

using namespace SExprLib;

int main() {
  std::cout << eval(parse(std::cin)) << std::endl;
  return 0;
}
