#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <iosfwd>

class Expr;

struct Parser {
  // A type defining a parser function pointer type, for functions such as:
  // expr, factor, term, digit
  using SubParserPtr = Expr*(Parser::*)();

  std::string la;
  std::istream* in;

  Parser(std::istream&);

  void next();

  template <typename T>
    void match(T&);

  template <typename T>
    bool optMatch(T&);

  template <typename MapType>
    Expr* binaryOpParse(MapType&, SubParserPtr);

  Expr* expr();
  Expr* factor();
  Expr* term();
  Expr* digit();
};

inline Expr* parse(std::istream& is) {
  Parser p(is);
  return p.expr();
}

#endif
