#include "PostfixVisitor.hpp"

#include "../Expr/AddExpr.hpp"
#include "../Expr/Digit.hpp"
#include "../Expr/DivExpr.hpp"
#include "../Expr/ModExpr.hpp"
#include "../Expr/MultiExpr.hpp"
#include "../Expr/SubExpr.hpp"

#include <iostream>

int main() {
  Digit a(1);
  Digit b(2);
  Digit c(3);
  Digit d(4);
  Digit e(5);

  AddExpr ab(a, b);
  MultiExpr abd(ab, d);
  AddExpr eabd(e, abd);
  SubExpr eabdc(eabd, c);

  std::cout << eval(ab) << '\n';
  std::cout << eval(abd) << '\n';
  std::cout << eval(eabd) << '\n';
  std::cout << eval(eabdc) << '\n';

  return 0;
}
