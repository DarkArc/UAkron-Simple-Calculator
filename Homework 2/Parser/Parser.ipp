#include "../Lexer/SymbolTable.hpp"
#include "../Lexer/Lexer.hpp"

inline
Parser::Parser(std::vector<Token>& tokens) : tokens(tokens), cur(tokens.begin()), end(tokens.end()) { }

inline Expr*
parse(std::istream& input) {
  SymbolTable table;
  tokenize(table, input);
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
    while ((it = map.find(static_cast<int>(cur->type))) != map.end()) {
      ++cur;
      Expr* e2 = (this->*subParse)();
      e1 = (this->*(it->second))(e1, e2);
    }
    return e1;
  }
