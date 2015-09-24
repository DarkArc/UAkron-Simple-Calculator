#include "SExprVisitor.hpp"

#include "../../Expr/BinaryExpr.hpp"

#include "../../Expr/AddExpr.hpp"
#include "../../Expr/Digit.hpp"
#include "../../Expr/DivExpr.hpp"
#include "../../Expr/ModExpr.hpp"
#include "../../Expr/MultiExpr.hpp"
#include "../../Expr/SubExpr.hpp"

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

void SExprVisitor::visit(Digit& expr) {
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
