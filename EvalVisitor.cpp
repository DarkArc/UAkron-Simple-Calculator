#include "EvalVisitor.hpp"

#include "Expr/BinaryExpr.hpp"

#include "Expr/AddExpr.hpp"
#include "Expr/Digit.hpp"
#include "Expr/DivExpr.hpp"
#include "Expr/ModExpr.hpp"
#include "Expr/MultiExpr.hpp"
#include "Expr/SubExpr.hpp"

#include <array>

using TwoArgExpr = std::array<int, 2>;

TwoArgExpr visitBinary(EvalVisitor& v, BinaryExpr& expr) {
  TwoArgExpr result;

  expr.leftExpr->accept(v);
  result[0] = v.result;

  expr.rightExpr->accept(v);
  result[1] = v.result;

  return result;
}

void EvalVisitor::visit(AddExpr& expr) {
  TwoArgExpr arg = visitBinary(*this, expr);
  result = arg[0] + arg[1];
}

void EvalVisitor::visit(Digit& expr) {
  result = expr.val;
}

void EvalVisitor::visit(DivExpr& expr) {
  TwoArgExpr arg = visitBinary(*this, expr);
  result = arg[0] / arg[1];
}

void EvalVisitor::visit(ModExpr& expr) {
  TwoArgExpr arg = visitBinary(*this, expr);
  result = arg[0] % arg[1];
}

void EvalVisitor::visit(MultiExpr& expr) {
  TwoArgExpr arg = visitBinary(*this, expr);
  result = arg[0] * arg[1];
}

void EvalVisitor::visit(SubExpr& expr) {
  TwoArgExpr arg = visitBinary(*this, expr);
  result = arg[0] - arg[1];
}
