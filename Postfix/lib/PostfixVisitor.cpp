#include "PostfixVisitor.hpp"

#include "../../AST/AST.hpp"

namespace {

  using namespace PostfixLib;

  std::string wrap(std::string op, BinaryExpr& expr) {
    return eval(expr.leftExpr) + " " + eval(expr.rightExpr) + " " + op;
  }
}

namespace PostfixLib {

void PostfixVisitor::visit(AddExpr& expr) {
  result = wrap("+", expr);
}

void PostfixVisitor::visit(Digits& expr) {
  result = std::to_string(expr.val);
}

void PostfixVisitor::visit(DivExpr& expr) {
  result = wrap("/", expr);
}

void PostfixVisitor::visit(ModExpr& expr) {
  result = wrap("%", expr);
}

void PostfixVisitor::visit(MultiExpr& expr) {
  result = wrap("*", expr);
}

void PostfixVisitor::visit(SubExpr& expr) {
  result = wrap("-", expr);
}

}
