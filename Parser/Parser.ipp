#include <stdexcept>

inline Expr* parse(std::istream& is) {
  Parser p(is);
  return p.expr();
}

template <typename T>
  inline void Parser::match(T& e) {
    if (!optMatch(e)) {
      throw std::logic_error("Invalid syntax");
    }
  }

template <typename T>
  inline bool Parser::optMatch(T& e) {
    if (e == la) {
      next();
      return true;
    }
    return false;
  }

template <typename MapType>
  inline Expr* Parser::binaryOpParse(MapType& map, SubParserPtr subParse) {

    // Call the recursive function
    Expr* e1 = (this->*subParse)();

    typename MapType::iterator it;

    // While the operator in the map is valid, remove
    // the current look ahead, call the recursive function
    // and join using the correct AST node, as determined
    // by the corresponding factory
    while ((it = map.find(la)) != map.end()) {
      next();
      Expr* e2 = (this->*subParse)();
      e1 = it->second(e1, e2);
    }
    return e1;
  }
