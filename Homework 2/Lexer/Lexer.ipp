#include <sstream>

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
  out.push_back(tokenFromTable(*symTable, text, tok));
  text.clear();

  input.reparse(predictor.prediction);
  predictor.prediction.clear();
}

inline char
Lexer::readLA() {
  char la = input.readLA();
  text += la;
  return la;
}

inline std::vector<Token>
tokenize(SymbolTable& symTable, std::istream& input) {
  Lexer l(symTable, input);
  auto tokenStream = l.tokenize();

  if (tokenStream.empty()) {
    throw std::runtime_error("No tokens presented in input stream");
  }

  return tokenStream;
}
