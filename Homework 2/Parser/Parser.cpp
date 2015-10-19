#include "Parser.hpp"

#include "../AST/AST.hpp"

using FactoryPtr = Expr*(Parser::*)(Expr*, Expr*);
using FactoryMap = std::unordered_map<int, FactoryPtr>;

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

}

// multiplicative-expr -> multiplicative-expr * unary-expr
//                      | multiplicative-expr / unary-expr
//                      | multiplicative-expr % unary-expr
//                      | unary-expr
Expr*
Parser::multiplicativeExpr() {
  FactoryMap vals{
    {static_cast<int>(TokType::STAR), &Parser::binaryFactory<MultiExpr>},
    {static_cast<int>(TokType::SLASH), &Parser::binaryFactory<DivExpr>},
    {static_cast<int>(TokType::PERCENT), &Parser::binaryFactory<ModExpr>}
  };

  return binaryOpParse<FactoryMap>(vals, &Parser::orderingExpr);
}

// additive-expr -> additive-expr + multiplicative-expr
//                | additive-expr - multiplicative-expr
//                | multiplicative-expr
Expr*
Parser::additiveExpr() {
  FactoryMap vals{
    {static_cast<int>(TokType::PLUS), &Parser::binaryFactory<AddExpr>},
    {static_cast<int>(TokType::MINUS), &Parser::binaryFactory<SubExpr>}
  };

  return binaryOpParse<FactoryMap>(vals, &Parser::multiplicativeExpr);
}

// ordering-expr -> ordering-expr '<' additive-expr
//                | ordering-expr '>' additive-expr
//                | ordering-expr '<=' additive-expr
//                | ordering-expr '>=' additive-expr
//                | additive-expr
Expr*
Parser::orderingExpr() {
  FactoryMap vals{
    {static_cast<int>(TokType::LESS_THAN), &Parser::binaryFactory<LessThanExpr>},
    {static_cast<int>(TokType::GREATER_THAN), &Parser::binaryFactory<GreaterThanExpr>},
    {static_cast<int>(TokType::LESS_THAN_EQ), &Parser::binaryFactory<LessThanEqualExpr>},
    {static_cast<int>(TokType::GREATHER_THAN_EQ), &Parser::binaryFactory<GreaterThanEqualExpr>}
  };

  return binaryOpParse<FactoryMap>(vals, &Parser::additiveExpr);
}

// equality-expr -> equality-expr '==' ordering-expr
//                | equality-expr '!=' ordering-expr
//                | ordering-expr
Expr*
Parser::equalityExpr() {
  FactoryMap vals{
    {static_cast<int>(TokType::EQUAL), &Parser::binaryFactory<EqualExpr>},
    {static_cast<int>(TokType::NOT_EQ), &Parser::binaryFactory<NotEqualExpr>}
  };

  return binaryOpParse<FactoryMap>(vals, &Parser::orderingExpr);
}

// logical-and-expr -> logical-and-expr '&&' ordering-expr
//                   | equality-expr
Expr*
Parser::logicalAndExpr() {
  FactoryMap vals{
    {static_cast<int>(TokType::AND), &Parser::binaryFactory<AndExpr>}
  };

  return binaryOpParse<FactoryMap>(vals, &Parser::equalityExpr);
}

// logical-or-expr -> logical-or-expr '||' logical-and-expr
//                  | logical-and-expr
Expr*
Parser::logicalOrExpr() {
  FactoryMap vals{
    {static_cast<int>(TokType::OR), &Parser::binaryFactory<OrExpr>}
  };

  return binaryOpParse<FactoryMap>(vals, &Parser::logicalAndExpr);
}

// expr -> logical-or-expr
Expr*
Parser::expr() {
  return logicalOrExpr();
}
