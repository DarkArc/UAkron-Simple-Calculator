#include "PostfixTest.hpp"

#include "../Parser/Parser.hpp"
#include "../Postfix/lib/PostfixVisitor.hpp"

using namespace PostfixLib;

void PostfixTest::complete() {
  expect<std::string>(eval(parse("2+2")), "2 2 +");
  expect<std::string>(eval(parse("2 + 2")), "2 2 +");
  expect<std::string>(eval(parse("9 - 5 + 2")), "9 5 - 2 +");
  expect<std::string>(eval(parse("1 + 2 * 3")), "1 2 3 * +");
}
