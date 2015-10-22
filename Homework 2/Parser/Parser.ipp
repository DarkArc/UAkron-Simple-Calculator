#include "../Lexer/SymbolTable.hpp"
#include "../Lexer/Lexer.hpp"

inline
Parser::Parser(std::vector<Token>& tokens) : tokens(tokens), cur(tokens.begin()), end(tokens.end()) { }

inline Expr*
parse(std::istream& input) {
  SymbolTable table;
  auto tokenStream = tokenize(table, input);
  Parser p(tokenStream);
  return p.expr();
}

template <typename T>
  inline void
  Parser::match(const T& t) {
    if (!optMatch(t)) {
      throw std::logic_error("Invalid syntax");
    }
  }

template <typename T>
  inline bool
  Parser::optMatch(const T& t) {
    if (t == cur->type) {
      cur++;
      return true;
    }
    return false;
  }

template <typename FactoryType>
  inline Expr*
  Parser::unaryFactory(Expr* e1) {
    return new FactoryType(*e1);
  }

template <typename MapType>
  inline Expr*
  Parser::unaryOpParse(MapType& map, SubParserPtr subParse) {

    typename MapType::iterator it;

    if ((it = map.find(cur->type)) != map.end()) {
      ++cur;
      return (this->*(it->second))(unaryOpParse<MapType>(map, subParse));
    }
    return (this->*subParse)();
  }

template <typename FactoryType>
  inline Expr*
  Parser::binaryFactory(Expr* e1, Expr* e2) {
    return new FactoryType(*e1, *e2);
  }

template <typename MapType>
  inline Expr*
  Parser::binaryOpParse(MapType& map, SubParserPtr subParse) {

    // Call the recursive function
    Expr* e1 = (this->*subParse)();

    typename MapType::iterator it;

    // While the operator in the map is valid, remove
    // the current look ahead, call the recursive function
    // and join using the correct AST node, as determined
    // by the corresponding factory
    while ((it = map.find(cur->type)) != map.end()) {
      ++cur;
      Expr* e2 = (this->*subParse)();
      e1 = (this->*(it->second))(e1, e2);
    }
    return e1;
  }
