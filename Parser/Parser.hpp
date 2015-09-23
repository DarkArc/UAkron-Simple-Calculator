#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <iostream>

class Expr;

struct Parser {
  std::string la;
  std::istream* in;

  Parser(std::istream&);

  void next();

  template <typename T>
    void match(T&);

  template <typename T>
    bool optMatch(T&);

  Expr* expr();
  Expr* factor();
  Expr* term();
  Expr* digit();
};

#endif
