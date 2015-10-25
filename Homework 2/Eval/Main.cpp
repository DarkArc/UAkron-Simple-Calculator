#include "lib/EvalVisitor.hpp"

#include "../Parser/Parser.hpp"

#include <iostream>

using namespace EvalLib;

void executeFor(std::istream* input) {
  std::string str;

  std::getline(*input, str);

  if (str.empty()) {
    return;
  }

  std::stringstream ss(str);
  std::cout << prettyEval(parse(ss)) << std::endl;
}

int main(int argc, char* argv[]) {
  std::istream* input = &std::cin;

  if (argc == 2) {
    if (std::string(argv[1]) == "multiline") {
      while (*input) {
        executeFor(input);
      }
    }
  } else {
    executeFor(input);
  }

  return 0;
}
