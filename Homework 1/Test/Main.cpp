#include "TestCore.hpp"

#include "EvalTest.hpp"
#include "PostfixTest.hpp"
#include "SExprTest.hpp"

#include <vector>
#include <iostream>
#include <exception>

int main() {
  std::vector<Test*> tests{
    new EvalTest(),
    new PostfixTest(),
    new SExprTest()
  };

  std::cout << "## Beginning testing..." << std::endl;

  for (auto&& test : tests) {
    try {
      test->complete();
    } catch (const std::exception& ex) {
      std::cerr << ex.what() << std::endl;
    }
  }

  std::cout << "## Test complete, if any other output is shown, the test failed." << std::endl;

  return 0;
}
