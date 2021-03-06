#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "SymbolTable.hpp"

#include <string>

enum class TokType {
  L_PAREN,
  R_PAREN,
  PLUS,
  MINUS,
  STAR,
  SLASH,
  PERCENT,
  KW_TRUE,
  KW_FALSE,
  AND,
  OR,
  NOT,
  EQUAL,
  NOT_EQ,
  LESS_THAN,
  LESS_THAN_EQ,
  GREATER_THAN,
  GREATHER_THAN_EQ,
  INT
};

struct Token {
  TokType type;
  Symbol* sym;

  Token(const TokType&, Symbol*);
};

Token tokenFromTable(SymbolTable&, const std::string&, const TokType&);

#include "Token.ipp"

#endif
