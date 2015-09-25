#include "Parser.hpp"

#include "../Expr/AddExpr.hpp"
#include "../Expr/Digit.hpp"
#include "../Expr/DivExpr.hpp"
#include "../Expr/ModExpr.hpp"
#include "../Expr/MultiExpr.hpp"
#include "../Expr/SubExpr.hpp"

#include <iostream>
#include <stdexcept>
#include <unordered_map>

using FactoryPtr = Expr*(*)(Expr*, Expr*);

namespace {
  Expr* addFactory(Expr* e1, Expr* e2) {
    return new AddExpr(*e1, *e2);
  }

  Expr* subFactory(Expr* e1, Expr* e2) {
    return new SubExpr(*e1, *e2);
  }

  Expr* multiFactory(Expr* e1, Expr* e2) {
    return new MultiExpr(*e1, *e2);
  }

  Expr* divFactory(Expr* e1, Expr* e2) {
    return new DivExpr(*e1, *e2);
  }

  Expr* modFactory(Expr* e1, Expr* e2) {
    return new ModExpr(*e1, *e2);
  }
}

Parser::Parser(std::istream& in) : in(&in) {
  next();
}

void Parser::next() {
  do {
    la = static_cast<char>(in->get());
  } while (la == " ");

  // EOF is determined by the last operation
  // thus, if this is true, we've reached the last character
  // this adds coverage for any input which does not end in
  // a new line.

  // This intern allows for the parse function to check explicitly
  // to ensure that the last la is a new line character
  // to validate that no trailing characters persist for this expression
  // in the input stream.
  if (in->eof()) {
    la = "\n";
  }
}

Expr* Parser::expr() {
  using FactoryMap = std::unordered_map<std::string, FactoryPtr>;

  FactoryMap vals{
    {"+", &::addFactory},
    {"-", &::subFactory}
  };

  return binaryOpParse<FactoryMap>(vals, &Parser::factor);
}


Expr* Parser::factor() {
  using FactoryMap = std::unordered_map<std::string, FactoryPtr>;

  FactoryMap vals{
    {"*", &::multiFactory},
    {"/", &::divFactory},
    {"%", &::modFactory}
  };

  return binaryOpParse<FactoryMap>(vals, &Parser::term);
}

Expr* Parser::term() {
  if (optMatch("(")) {
    Expr* e1 = expr();
    match(")");
    return e1;
  } else {
    return digit();
  }
}

Expr* Parser::digit() {
  std::unordered_map<std::string, int> vals{
    {"0", 0},
    {"1", 1},
    {"2", 2},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9}
  };

  bool found = false;
  int val = 0;

  // Translate multidigit  numbers from text to an integer value
  while (true) {
    auto it = vals.find(la);
    if (it == vals.end()) {
      break;
    }

    found = true;

    val *= 10;
    val += it->second;

    next();
  }

  if (!found) {
    throw std::logic_error("Invalid syntax");
  }

  return new Digit(val);
}
