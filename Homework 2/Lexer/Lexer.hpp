#pragma once

#include "Token.hpp"

#include <vector>
#include <iosfwd>

class Lexer {
  std::istream* input;
  std::string text;
  std::string prediction;
  std::vector<Token> out;

public:
  Lexer(std::istream&);

  std::vector<Token> tokenize();

private:
  void addTok(const TokType&);
  void addOrigTok(const TokType&);
  bool predict(const std::string&);
  char readLA();
}

std::vector<Token> tokenize(std::istream& input);

#include "Lexer.ipp"
