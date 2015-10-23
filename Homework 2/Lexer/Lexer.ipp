#include <sstream>
#include <iostream>

inline
ReparseStream::ReparseStream(std::istream& input) : input(&input) { }

inline
Predictor::Predictor(ReparseStream& stream, Lexer& lexer) : stream(&stream), lexer(&lexer) { }

inline
Predictor::~Predictor() {
  if (!prediction.empty()) {
    std::runtime_error("Illegal lexer state!");
  }
}

inline
Lexer::Lexer(SymbolTable& symTable, std::istream& input) : symTable(&symTable), input(ReparseStream(input)) { }

inline void
Lexer::addTok(const TokType& tok, Predictor& predictor) {
  out.push_back(tokenFromTable(*symTable, text, tok));
  text.clear();

  predictor.prediction.clear();
}

inline void
Lexer::addOrigTok(const TokType& tok, Predictor& predictor) {
  std::string* prediction = &predictor.prediction;
  out.push_back(tokenFromTable(*symTable, text.substr(0, text.size() - prediction->size()), tok));
  text = *prediction;

  prediction->clear();
}

inline char
Lexer::readLA() {
  char la = input.readLA();
  text += la;
  return la;
}

inline std::vector<Token>
tokenize(SymbolTable& symTable, std::istream& input) {
  std::string str;
  std::getline(input, str);
  std::stringstream ss(str);
  Lexer l(symTable, ss);
  return l.tokenize();
}
