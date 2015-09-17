#include "SExprVisitor.hpp"

#include "../Expr/AddExpr.hpp"
#include "../Expr/Digit.hpp"
#include "../Expr/DivExpr.hpp"
#include "../Expr/ModExpr.hpp"
#include "../Expr/MultiExpr.hpp"
#include "../Expr/SubExpr.hpp"

#include <iostream>

int main() {
  Digit a(5);
  Digit b(2);
  AddExpr exprA(a, b);
  AddExpr exprB(exprA, b);
  MultiExpr exprC(exprA, exprB);

  std::cout << eval(exprA) << '\n';
  std::cout << eval(exprB) << '\n';
  std::cout << eval(exprC) << '\n';

  return 0;
}
