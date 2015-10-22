inline
Token::Token(const TokType& type, Symbol* sym) : type(type), sym(sym) { }

inline Token
tokenFromTable(SymbolTable& table, const std::string& text, const TokType& tokType) {
  auto res = table.insert({text, nullptr});

  Symbol* sym;
  if (res.second) {
    if (tokType == TokType::INT) {
      res.first->second = sym = new IntValueSymbol(tokType, text, std::stoi(text));
    } else if (tokType == TokType::KW_TRUE) {
      res.first->second = sym = new IntValueSymbol(tokType, text, true);
    } else if (tokType == TokType::KW_FALSE) {
      res.first->second = sym = new IntValueSymbol(tokType, text, false);
    } else {
      res.first->second = sym = new Symbol(tokType, text);
    }
  } else {
    sym = res.first->second;
  }

  return Token(tokType, sym);
}
