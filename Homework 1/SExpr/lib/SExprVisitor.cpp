#include "SExprVisitor.hpp"

#include "../../AST/AST.hpp"

namespace {

  using namespace SExprLib;

  std::string wrap(std::string op, BinaryExpr& expr) {
    return "(" + op + " " + eval(expr.leftExpr) + " " + eval(expr.rightExpr) + ")";
  }
}

namespace SExprLib {

void SExprVisitor::visit(AddExpr& expr) {
  result = wrap("+", expr);
}

void SExprVisitor::visit(Digits& expr) {
  result = std::to_string(expr.val);
}

void SExprVisitor::visit(DivExpr& expr) {
  result = wrap("/", expr);
}

void SExprVisitor::visit(ModExpr& expr) {
  result = wrap("%", expr);
}

void SExprVisitor::visit(MultiExpr& expr) {
  result = wrap("*", expr);
}

void SExprVisitor::visit(SubExpr& expr) {
  result = wrap("-", expr);
}

}
