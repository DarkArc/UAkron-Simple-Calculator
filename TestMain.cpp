#include "EvalVisitor.hpp"

#include "Expr/AddExpr.hpp"
#include "Expr/Digit.hpp"
#include "Expr/DivExpr.hpp"
#include "Expr/ModExpr.hpp"
#include "Expr/MultiExpr.hpp"
#include "Expr/SubExpr.hpp"

#include <iostream>

int main() {
  Digit a(5);
  Digit b(2);
  AddExpr exprA(a, b);
  AddExpr exprB(exprA, b);
  MultiExpr exprC(exprA, exprB);

  EvalVisitor v;

  v.visit(exprA);
  std::cout << v.result << std::endl;

  v.visit(exprB);
  std::cout << v.result << std::endl;

  v.visit(exprC);
  std::cout << v.result << std::endl;

  return 0;
}
