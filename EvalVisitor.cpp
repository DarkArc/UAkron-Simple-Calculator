#include "EvalVisitor.hpp"

#include "BinaryExpr.hpp"

#include "AddExpr.hpp"
#include "Digit.hpp"
#include "DivExpr.hpp"
#include "ModExpr.hpp"
#include "MultiExpr.hpp"
#include "SubExpr.hpp"

#include <array>

std::array<int, 2> visitBinary(EvalVisitor& v, BinaryExpr& expr) {
  std::array<int, 2> result;

  expr.leftExpr->accept(v);
  result[0] = v.result;

  expr.rightExpr->accept(v);
  result[1] = v.result;

  return result;
}

void EvalVisitor::visit(AddExpr& expr) {
  std::array<int, 2> lr = visitBinary(*this, expr);
  result = lr[0] + lr[1];
}

void EvalVisitor::visit(Digit& expr) {
  result = expr.val;
}

void EvalVisitor::visit(DivExpr& expr) {
  std::array<int, 2> lr = visitBinary(*this, expr);
  result = lr[0] / lr[1];
}

void EvalVisitor::visit(ModExpr& expr) {
  std::array<int, 2> lr = visitBinary(*this, expr);
  result = lr[0] % lr[1];
}

void EvalVisitor::visit(MultiExpr& expr) {
  std::array<int, 2> lr = visitBinary(*this, expr);
  result = lr[0] * lr[1];
}

void EvalVisitor::visit(SubExpr& expr) {
  std::array<int, 2> lr = visitBinary(*this, expr);
  result = lr[0] - lr[1];
}
