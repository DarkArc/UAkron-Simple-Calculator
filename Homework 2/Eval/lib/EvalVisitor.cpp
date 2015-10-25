#include "EvalVisitor.hpp"

#include "../../AST/AST.hpp"

#include <stdexcept>

namespace EvalLib {


void EvalVisitor::visit(AddExpr& expr) {
  result = eval(expr.leftExpr).value + eval(expr.rightExpr).value;
}

void EvalVisitor::visit(AndExpr& expr) {
  result = eval(expr.leftExpr).value && eval(expr.rightExpr).value;
}

void EvalVisitor::visit(BinaryValExpr& expr) {
  result = expr.val;
}

void EvalVisitor::visit(DivExpr& expr) {
  result = eval(expr.leftExpr).value / eval(expr.rightExpr).value;
}

void EvalVisitor::visit(EqualExpr& expr) {
  result = eval(expr.leftExpr).value == eval(expr.rightExpr).value;
}

void EvalVisitor::visit(GreaterThanEqualExpr& expr) {
  result = eval(expr.leftExpr).value >= eval(expr.rightExpr).value;
}

void EvalVisitor::visit(GreaterThanExpr& expr) {
  result = eval(expr.leftExpr).value > eval(expr.rightExpr).value;
}

void EvalVisitor::visit(IntegerValExpr& expr) {
  result = expr.val;
}

void EvalVisitor::visit(LessThanEqualExpr& expr) {
  result = eval(expr.leftExpr).value <= eval(expr.rightExpr).value;
}

void EvalVisitor::visit(LessThanExpr& expr) {
  result = eval(expr.leftExpr).value < eval(expr.rightExpr).value;
}

void EvalVisitor::visit(ModExpr& expr) {
  result = eval(expr.leftExpr).value % eval(expr.rightExpr).value;
}

void EvalVisitor::visit(MultiExpr& expr) {
  result = eval(expr.leftExpr).value * eval(expr.rightExpr).value;
}

void EvalVisitor::visit(NegationExpr& expr) {
  result = !eval(expr.expr).value;
}

void EvalVisitor::visit(NegExpr& expr) {
  result = -eval(expr.expr).value;
}

void EvalVisitor::visit(NotEqualExpr& expr) {
  result = eval(expr.leftExpr).value != eval(expr.rightExpr).value;
}

void EvalVisitor::visit(OrExpr& expr) {
  result = eval(expr.leftExpr).value || eval(expr.rightExpr).value;
}

void EvalVisitor::visit(PosExpr& expr) {
  result = eval(expr.expr).value;
}

void EvalVisitor::visit(SubExpr& expr) {
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
