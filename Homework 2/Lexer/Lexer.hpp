#pragma once

#include "Token.hpp"

#include <vector>
#include <iosfwd>

struct ReparseStream {
  std::string reparse;
  std::istream* input;

  ReparseStream(std::istream&);

  bool eof();
  char readLA();

  void reparse(const std::string&);
};

struct Predictor {
  std::string prediction;
  ReparseStream* stream;
  Lexer* lexer;

  Predictor(ReparseStream&, Lexer&)
  ~Predictor();

  bool operator () (const std::string&);
};

class Lexer {
  ReparseStream* input;
  std::string text;
  std::vector<Token> out;

public:
  Lexer(std::istream&);

  std::vector<Token> tokenize();

private:
  void addTok(const TokType&);
  void addOrigTok(const TokType&, const Predictor&);
  char readLA();
}

std::vector<Token> tokenize(std::istream& input);

#include "Lexer.ipp"
