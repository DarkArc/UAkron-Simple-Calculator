#include "EvalVisitor.hpp"

#include "AddExpr.hpp"
#include "Digit.hpp"
#include "DivExpr.hpp"
#include "ModExpr.hpp"
#include "MultiExpr.hpp"
#include "SubExpr.hpp"

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
