#include "EvalVisitor.hpp"

#include "../Expr/AddExpr.hpp"
#include "../Expr/Digit.hpp"
#include "../Expr/DivExpr.hpp"
#include "../Expr/ModExpr.hpp"
#include "../Expr/MultiExpr.hpp"
#include "../Expr/SubExpr.hpp"

#include "../Parser/Parser.hpp"

#include <iostream>
#include <sstream>

int main() {
  // Digit a(5);
  // Digit b(2);
  // AddExpr exprA(a, b);
  // AddExpr exprB(exprA, b);
  // MultiExpr exprC(exprA, exprB);

  std::stringstream k;
  k << "(( 1 + 2 ) * 5 )\n";
  Parser p(k);
  std::cout << eval(p.expr()) << '\n';
  // std::cout << eval(exprB) << '\n';
  // std::cout << eval(exprC) << '\n';

  return 0;
}
