#include "TypeChecker.hpp"

#include <stdexcept>

namespace {
  void assertEqual(Type* a, Type* b) {
    if (a != b) {
      throw std::runtime_error("Illegal type state");
    }
  }

  Type* assertUnuaryType(UnaryExpr& expr, Type* type) {
    ::assertEqual(typeCheck(expr.expr), type);
    return type;
  }

  Type* assertBinaryType(BinaryExpr& expr, Type* type) {
    Type* leftType = typeCheck(expr.leftExpr);
    Type* rightType = typeCheck(expr.rightExpr);

    ::assertEqual(leftType, type);
    ::assertEqual(rightType, type);

    return type;
  }
}

void TypeCheckVisitor::visit(AddExpr& expr) {
  result = ::assertBinaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(AndExpr& expr) {
  result = ::assertBinaryType(expr, getBoolType());
}

void TypeCheckVisitor::visit(BinaryValExpr& expr) {
  result = getBoolType();
}

void TypeCheckVisitor::visit(DivExpr& expr) {
  result = ::assertBinaryType(expr, getBoolType());
}

void TypeCheckVisitor::visit(EqualExpr& expr) {
  Type* leftType = typeCheck(expr.leftExpr);
  Type* rightType = typeCheck(expr.rightExpr);

  ::assertEqual(leftType, rightType);

  result = leftType;
}

void TypeCheckVisitor::visit(GreaterThanEqualExpr& expr) {
  result = ::assertBinaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(GreaterThanExpr& expr) {
  result = ::assertBinaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(IntegerValExpr& expr) {
  result = getIntType();
}

void TypeCheckVisitor::visit(LessThanEqualExpr& expr) {
  result = ::assertBinaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(LessThanExpr& expr) {
  result = ::assertBinaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(ModExpr& expr) {
  result = ::assertBinaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(MultiExpr& expr) {
  result = ::assertBinaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(NegationExpr& expr) {
  result = ::assertUnuaryType(expr, getBoolType());
}

void TypeCheckVisitor::visit(NegExpr& expr) {
  result = ::assertUnuaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(NotEqualExpr& expr) {
  result = ::assertBinaryType(expr, getBoolType());
}

void TypeCheckVisitor::visit(OrExpr& expr) {
  result = ::assertBinaryType(expr, getBoolType());
}

void TypeCheckVisitor::visit(PosExpr& expr) {
  result = ::assertUnuaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(SubExpr& expr) {
  result = ::assertBinaryType(expr, getIntType());
}
