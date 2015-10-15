#include "lib/EvalVisitor.hpp"

#include "../Parser/Parser.hpp"

#include <iostream>

using namespace EvalLib;

int main() {
  std::cout << eval(parse(std::cin)) << std::endl;
  return 0;
}
