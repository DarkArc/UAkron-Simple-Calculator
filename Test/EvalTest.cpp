#include "EvalTest.hpp"

#include "../Parser/Parser.hpp"
#include "../Eval/lib/EvalVisitor.hpp"

using namespace EvalLib;

void EvalTest::complete() {
  expect<int>(eval(parse("2+2")), 4, "2+2 != 4");
  expect<int>(eval(parse("2 + 2")), 4, "2 + 2 != 4");
  expect<int>(eval(parse("2-2")), 0, "2-2 != 0");
  expect<int>(eval(parse("2 - 2")), 0, "2 - 2 != 0");
  expect<int>(eval(parse("2 * 5")), 10, "2*5 != 10");
  expect<int>(eval(parse("2 * 5")), 10, "2 * 5 != 10");
  expect<int>(eval(parse("10/2")), 5, "10/2 != 5");
  expect<int>(eval(parse("10 / 2")), 5, "10 / 2 != 5");
  expect<int>(eval(parse("10%7")), 3, "10%7 != 3");
  expect<int>(eval(parse("10 % 7")), 3, "10 % 7 != 3");
  expect<int>(eval(parse("2 + 3 * 5")), 17, "2 + 3 * 5 != 17");
  expect<int>(eval(parse("(2+3) * 5")), 25, "(2+3) * 5 != 25");
  expect<int>(eval(parse("(2 + 3) * 5")), 25, "(2 + 3) * 5 != 25");
}
