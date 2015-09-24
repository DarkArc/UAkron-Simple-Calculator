#include "lib/SExprVisitor.hpp"

#include "../Expr/AddExpr.hpp"
#include "../Expr/Digit.hpp"
#include "../Expr/DivExpr.hpp"
#include "../Expr/ModExpr.hpp"
#include "../Expr/MultiExpr.hpp"
#include "../Expr/SubExpr.hpp"

#include "../Parser/Parser.hpp"

#include <iostream>

using namespace SExprLib;

int main() {
  std::cout << eval(parse(std::cin)) << std::endl;
  return 0;
}
