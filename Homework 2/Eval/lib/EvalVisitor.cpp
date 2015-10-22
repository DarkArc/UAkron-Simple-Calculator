#include "EvalVisitor.hpp"

#include "../../AST/AST.hpp"

namespace EvalLib {

void EvalVisitor::visit(AddExpr& expr) {
  result = eval(expr.leftExpr) + eval(expr.rightExpr);
}

void EvalVisitor::visit(AndExpr& expr) {

}

void EvalVisitor::visit(BinaryValExpr& expr) {

}

void EvalVisitor::visit(DivExpr& expr) {
  result = eval(expr.leftExpr) / eval(expr.rightExpr);
}

void EvalVisitor::visit(EqualExpr& expr) {

}

void EvalVisitor::visit(GreaterThanEqualExpr& expr) {

}

void EvalVisitor::visit(GreaterThanExpr& expr) {

}

void EvalVisitor::visit(IntegerValExpr& expr) {
  result = expr.val;
}

void EvalVisitor::visit(LessThanEqualExpr& expr) {

}

void EvalVisitor::visit(LessThanExpr& expr) {

}

void EvalVisitor::visit(ModExpr& expr) {
  result = eval(expr.leftExpr) % eval(expr.rightExpr);
}

void EvalVisitor::visit(MultiExpr& expr) {
  result = eval(expr.leftExpr) * eval(expr.rightExpr);
}

void EvalVisitor::visit(NegationExpr& expr) {

}

void EvalVisitor::visit(NegExpr& expr) {

}

void EvalVisitor::visit(NotEqualExpr& expr) {

}

void EvalVisitor::visit(OrExpr& expr) {

}

void EvalVisitor::visit(PosExpr& expr) {

}

void EvalVisitor::visit(SubExpr& expr) {
  result = eval(expr.leftExpr) - eval(expr.rightExpr);
}

}
