#pragma once

#include "../Lexer/Token.hpp"

#include <vector>
#include <iosfwd>

class Expr;

struct Parser {
  using SubParserPtr = Expr*(Parser::*)();

  std::vector<Token> tokens;
  std::vector<Token>::iterator cur;
  std::vector<Token>::iterator end;

  Parser(std::vector<Token>&);

  Expr* literal();
  Expr* primaryExpr();
  Expr* unaryExpr();
  Expr* multiplicativeExpr();
  Expr* additiveExpr();
  Expr* orderingExpr();
  Expr* equalityExpr();
  Expr* logicalAndExpr();
  Expr* logicalOrExpr();
  Expr* expr();

  template <typename T>
    void match(const T&);

  template <typename T>
    bool optMatch(const T&);

  template <typename FactoryType>
    Expr* unaryFactory(Expr*);

  template <typename MapType>
    Expr* unaryOpParse(MapType&, SubParserPtr);

  template <typename FactoryType>
    Expr* binaryFactory(Expr*, Expr*);

  template <typename MapType>
    Expr* binaryOpParse(MapType&, SubParserPtr);
};

Expr* parse(std::istream&);

#include "Parser.ipp"
