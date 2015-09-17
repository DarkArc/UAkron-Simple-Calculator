#include "EvalVisitor.hpp"

#include "Expr/BinaryExpr.hpp"

#include "Expr/AddExpr.hpp"
#include "Expr/Digit.hpp"
#include "Expr/DivExpr.hpp"
#include "Expr/ModExpr.hpp"
#include "Expr/MultiExpr.hpp"
#include "Expr/SubExpr.hpp"

#include <array>


void EvalVisitor::visit(AddExpr& expr) {
  result = eval(expr.leftExpr) + eval(expr.rightExpr);
}

void EvalVisitor::visit(Digit& expr) {
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
