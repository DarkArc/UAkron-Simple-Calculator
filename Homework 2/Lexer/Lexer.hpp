#pragma once

#include "Token.hpp"
#include "SymbolTable.hpp"

#include <vector>
#include <iosfwd>

struct ReparseStream;
struct Predictor;
class Lexer;

struct ReparseStream {
  std::string reparseText;
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

  Predictor(ReparseStream&, Lexer&);
  ~Predictor();

  bool operator () (const std::string&);
};

class Lexer {
  SymbolTable* symTable;
  ReparseStream input;
  std::string text;
  std::vector<Token> out;

public:
  Lexer(SymbolTable&, std::istream&);

  std::vector<Token> tokenize();

private:
  void consumeInt(char&, Predictor&);
  void addTok(const TokType&, Predictor&);
  void addOrigTok(const TokType&, Predictor&);
  char readLA();

  friend struct Predictor;
};

std::vector<Token> tokenize(SymbolTable&, std::istream& input);

#include "Lexer.ipp"
