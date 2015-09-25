#include "SExprTest.hpp"

#include "../Parser/Parser.hpp"
#include "../SExpr/lib/SExprVisitor.hpp"

using namespace SExprLib;

namespace {
  void expectVal(const std::string& str, const std::string& res) {
    expect<std::string>(eval(parse(str)), res);
  }
}

void SExprTest::complete() {
  expectVal("2+2", "(+ 2 2)");
  expectVal("2 + 2", "(+ 2 2)");
  expectVal("9 - 5 + 2", "(+ (- 9 5) 2)");
  expectVal("1 + 2 * 3", "(+ 1 (* 2 3))");
}
