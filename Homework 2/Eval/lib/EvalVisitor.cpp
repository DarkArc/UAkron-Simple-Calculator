#include "EvalVisitor.hpp"

#include "../../AST/AST.hpp"
#include "../../TypeChecker/TypeChecker.hpp"

#include <stdexcept>

namespace EvalLib {


void EvalVisitor::visit(AddExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value + eval(expr.rightExpr).value;
}

void EvalVisitor::visit(AndExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value && eval(expr.rightExpr).value;
}

void EvalVisitor::visit(BinaryValExpr& expr) {
  resultType = typeCheck(expr);
  result = expr.val;
}

void EvalVisitor::visit(DivExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value / eval(expr.rightExpr).value;
}

void EvalVisitor::visit(EqualExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value == eval(expr.rightExpr).value;
}

void EvalVisitor::visit(GreaterThanEqualExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value >= eval(expr.rightExpr).value;
}

void EvalVisitor::visit(GreaterThanExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value > eval(expr.rightExpr).value;
}

void EvalVisitor::visit(IntegerValExpr& expr) {
  resultType = typeCheck(expr);
  result = expr.val;
}

void EvalVisitor::visit(LessThanEqualExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value <= eval(expr.rightExpr).value;
}

void EvalVisitor::visit(LessThanExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value < eval(expr.rightExpr).value;
}

void EvalVisitor::visit(ModExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value % eval(expr.rightExpr).value;
}

void EvalVisitor::visit(MultiExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value * eval(expr.rightExpr).value;
}

void EvalVisitor::visit(NegationExpr& expr) {
  resultType = typeCheck(expr);
  result = !eval(expr.expr).value;
}

void EvalVisitor::visit(NegExpr& expr) {
  resultType = typeCheck(expr);
  result = -eval(expr.expr).value;
}

void EvalVisitor::visit(NotEqualExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value != eval(expr.rightExpr).value;
}

void EvalVisitor::visit(OrExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value || eval(expr.rightExpr).value;
}

void EvalVisitor::visit(PosExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.expr).value;
}

void EvalVisitor::visit(SubExpr& expr) {
  resultType = typeCheck(expr);
  result = eval(expr.leftExpr).value - eval(expr.rightExpr).value;
}

std::string prettyEval(Expr* e) {
  EvalValue result = eval(e);
  if (result.type == getIntType()) {
    return std::to_string(result.value);
  } else if (result.type == getBoolType()) {
    return result.value ? "true" : "false";
  }
  throw std::runtime_error("Illegal type state");
}

}
