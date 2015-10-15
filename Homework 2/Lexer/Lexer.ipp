inline void
Lexer::addTok(const TokType& tok) {
  out.emplace_back(tok, text);
  text.clear();
}

inline void
addOrigTok(const TokType& tok, const Predictor& predictor) {
  std::string* prediction = &predictor.prediction;
  out.emplace_back(tok, text.substring(0, text.size() - prediction->size()));
  text = *prediction;
  prediction->clear();
}

inline char
Lexer::readLA() {
  char la = input->readLA();
  text += la;
  return la;
}

inline std::vector<Token>
tokenize(std::istream& input) {
  Lexer l;
  return l.tokenize(input);
}
