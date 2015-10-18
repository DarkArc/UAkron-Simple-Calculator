inline
Token::Token(const TokType& type, Symbol* sym) : type(type), sym(sym) { }

inline Token
tokenFromTable(SymbolTable& table, const std::string& text, const TokType& tokType) {
  auto res = table.insert({text, nullptr});

  Symbol* sym;
  if (res.second) {
    res.first->second = sym = new Symbol(tokType, text);
  } else {
    sym = res.first->second;
  }

  return Token(tokType, sym);
}
