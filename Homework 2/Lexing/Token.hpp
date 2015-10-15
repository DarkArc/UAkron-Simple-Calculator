#ifndef TOKEN_HPP
#define TOKEN_HPP

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
  std::string text;

};

#include "Token.ipp"

#endif
