inline
Symbol::Symbol(const TokType& type, const std::string& s) : type(type), s(s) { }

inline
IntValueSymbol::IntValueSymbol(const TokType& type, const std::string& s, int value) : Symbol(type, s), value(value) { }
