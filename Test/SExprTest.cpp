#include "SExprTest.hpp"

#include "../Parser/Parser.hpp"
#include "../SExpr/lib/SExprVisitor.hpp"

using namespace SExprLib;

void SExprTest::complete() {
  expect<std::string>(eval(parse("2+2")), "(+ 2 2)");
  expect<std::string>(eval(parse("2 + 2")), "(+ 2 2)");
  expect<std::string>(eval(parse("9 - 5 + 2")), "(+ (- 9 5) 2)");
  expect<std::string>(eval(parse("1 + 2 * 3")), "(+ 1 (* 2 3))");
}
