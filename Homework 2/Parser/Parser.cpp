#include "Parser.hpp"

#include "../AST/AST.hpp"

namespace {
  // Special hash function required for enum class
  // This is a work around for GCC Bug #60970
  struct EnumClassHasher {
      template <typename T>
        unsigned int operator()(T t) const {
            return static_cast<unsigned int>(t);
        }
  };

  using UnaryFactoryPtr = Expr*(Parser::*)(Expr*);
  using BinaryFactoryPtr = Expr*(Parser::*)(Expr*, Expr*);

  template <typename FuncPtr>
    using FactoryMap = std::unordered_map<TokType, FuncPtr, EnumClassHasher>;

  using UnaryFactoryMap = FactoryMap<UnaryFactoryPtr>;
  using BinaryFactoryMap = FactoryMap<BinaryFactoryPtr>;
}

// primary-expr -> literal
//               | ( expr )
Expr*
Parser::primaryExpr() {

}

// unary-expr -> - unary-expr
//             | + unary-expr
//             | ! unary-expr
//             | primary-expr
Expr*
Parser::unaryExpr() {
  ::UnaryFactoryMap vals{
    {TokType::MINUS, &Parser::unaryFactory<NegExpr>},
    {TokType::PLUS, &Parser::unaryFactory<PosExpr>},
    {TokType::NOT, &Parser::unaryFactory<NegationExpr>}
  };

  return unaryOpParse<::UnaryFactoryMap>(vals, &Parser::primaryExpr);
}

// multiplicative-expr -> multiplicative-expr * unary-expr
//                      | multiplicative-expr / unary-expr
//                      | multiplicative-expr % unary-expr
//                      | unary-expr
Expr*
Parser::multiplicativeExpr() {
  ::BinaryFactoryMap vals{
    {TokType::STAR, &Parser::binaryFactory<MultiExpr>},
    {TokType::SLASH, &Parser::binaryFactory<DivExpr>},
    {TokType::PERCENT, &Parser::binaryFactory<ModExpr>}
  };

  return binaryOpParse<::BinaryFactoryMap>(vals, &Parser::unaryExpr);
}

// additive-expr -> additive-expr + multiplicative-expr
//                | additive-expr - multiplicative-expr
//                | multiplicative-expr
Expr*
Parser::additiveExpr() {
  ::BinaryFactoryMap vals{
    {TokType::PLUS, &Parser::binaryFactory<AddExpr>},
    {TokType::MINUS, &Parser::binaryFactory<SubExpr>}
  };

  return binaryOpParse<::BinaryFactoryMap>(vals, &Parser::multiplicativeExpr);
}

// ordering-expr -> ordering-expr '<' additive-expr
//                | ordering-expr '>' additive-expr
//                | ordering-expr '<=' additive-expr
//                | ordering-expr '>=' additive-expr
//                | additive-expr
Expr*
Parser::orderingExpr() {
  ::BinaryFactoryMap vals{
    {TokType::LESS_THAN, &Parser::binaryFactory<LessThanExpr>},
    {TokType::GREATER_THAN, &Parser::binaryFactory<GreaterThanExpr>},
    {TokType::LESS_THAN_EQ, &Parser::binaryFactory<LessThanEqualExpr>},
    {TokType::GREATHER_THAN_EQ, &Parser::binaryFactory<GreaterThanEqualExpr>}
  };

  return binaryOpParse<::BinaryFactoryMap>(vals, &Parser::additiveExpr);
}

// equality-expr -> equality-expr '==' ordering-expr
//                | equality-expr '!=' ordering-expr
//                | ordering-expr
Expr*
Parser::equalityExpr() {
  ::BinaryFactoryMap vals{
    {TokType::EQUAL, &Parser::binaryFactory<EqualExpr>},
    {TokType::NOT_EQ, &Parser::binaryFactory<NotEqualExpr>}
  };

  return binaryOpParse<::BinaryFactoryMap>(vals, &Parser::orderingExpr);
}

// logical-and-expr -> logical-and-expr '&&' ordering-expr
//                   | equality-expr
Expr*
Parser::logicalAndExpr() {
  ::BinaryFactoryMap vals{
    {TokType::AND, &Parser::binaryFactory<AndExpr>}
  };

  return binaryOpParse<::BinaryFactoryMap>(vals, &Parser::equalityExpr);
}

// logical-or-expr -> logical-or-expr '||' logical-and-expr
//                  | logical-and-expr
Expr*
Parser::logicalOrExpr() {
  ::BinaryFactoryMap vals{
    {TokType::OR, &Parser::binaryFactory<OrExpr>}
  };

  return binaryOpParse<::BinaryFactoryMap>(vals, &Parser::logicalAndExpr);
}

// expr -> logical-or-expr
Expr*
Parser::expr() {
  return logicalOrExpr();
}
