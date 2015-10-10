#include "EvalVisitor.hpp"

#include "../../AST/AST.hpp"

namespace EvalLib {

void EvalVisitor::visit(AddExpr& expr) {
  result = eval(expr.leftExpr) + eval(expr.rightExpr);
}

void EvalVisitor::visit(Digits& expr) {
  result = expr.val;
}

void EvalVisitor::visit(DivExpr& expr) {
  result = eval(expr.leftExpr) / eval(expr.rightExpr);
}

void EvalVisitor::visit(ModExpr& expr) {
  result = eval(expr.leftExpr) % eval(expr.rightExpr);
}

void EvalVisitor::visit(MultiExpr& expr) {
  result = eval(expr.leftExpr) * eval(expr.rightExpr);
}

void EvalVisitor::visit(SubExpr& expr) {
  result = eval(expr.leftExpr) - eval(expr.rightExpr);
}

}
