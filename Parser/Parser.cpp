#include "Parser.hpp"

#include "../Expr/AddExpr.hpp"
#include "../Expr/Digit.hpp"
#include "../Expr/DivExpr.hpp"
#include "../Expr/ModExpr.hpp"
#include "../Expr/MultiExpr.hpp"
#include "../Expr/SubExpr.hpp"

#include <iostream>
#include <exception>
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
}

template <typename T>
  void Parser::match(T& e) {
    if (!optMatch(e)) {
      throw std::logic_error("Invalid syntax");
    }
  }

template <typename T>
  bool Parser::optMatch(T& e) {
    if (e == la) {
      next();
      return true;
    }
    return false;
  }

template <typename MapType>
  Expr* Parser::binaryOpParse(MapType& map, SubParserPtr subParse) {

    // Call the recursive function
    Expr* e1 = (this->*subParse)();

    typename MapType::iterator it;

    // While the operator in the map is valid, remove
    // the current look ahead, call the recursive function
    // and join using the correct AST node, as determined
    // by the corresponding factory
    while ((it = map.find(la)) != map.end()) {
      next();
      Expr* e2 = (this->*subParse)();
      e1 = it->second(e1, e2);
    }
    return e1;
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
