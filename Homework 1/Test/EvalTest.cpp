#include "EvalTest.hpp"

#include "../Parser/Parser.hpp"
#include "../Eval/lib/EvalVisitor.hpp"

using namespace EvalLib;

namespace {
  void expectVal(const std::string& str, const int& val) {
    expect<int>(eval(parse(str)), val, str + " != " + std::to_string(val));
  }
}

void EvalTest::complete() {
  expectVal("2+2", 4);
  expectVal("2 + 2", 4);
  expectVal("2-2", 0);
  expectVal("2 - 2", 0);
  expectVal("2 * 5", 10);
  expectVal("2 * 5", 10);
  expectVal("10/2", 5);
  expectVal("10 / 2", 5);
  expectVal("10%7", 3);
  expectVal("10 % 7", 3);
  expectVal("2 + 3 * 5", 17);
  expectVal("(2+3) * 5", 25);
  expectVal("(2 + 3) * 5", 25);
}
