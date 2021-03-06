#include "TypeChecker.hpp"

#include <stdexcept>

namespace {
  void assertEqual(Type* a, Type* b) {
    if (a != b) {
      throw std::runtime_error("Illegal type state");
    }
  }

  Type* assertOrReturnUnuaryType(UnaryExpr& expr, Type* type) {
    if (expr.type != nullptr) {
      return expr.type;
    }

    ::assertEqual(typeCheck(expr.expr), type);
    return type;
  }

  Type* assertOrReturnBinarySameType(BinaryExpr& expr, Type* returnType) {
    if (expr.type != nullptr) {
      return expr.type;
    }

    Type* leftType = typeCheck(expr.leftExpr);
    Type* rightType = typeCheck(expr.rightExpr);

    ::assertEqual(leftType, rightType);

    return returnType;
  }

  Type* assertOrReturnBinaryType(BinaryExpr& expr, Type* type, Type* returnType) {
    if (expr.type != nullptr) {
      return expr.type;
    }

    Type* leftType = typeCheck(expr.leftExpr);
    Type* rightType = typeCheck(expr.rightExpr);

    ::assertEqual(leftType, type);
    ::assertEqual(rightType, type);

    return returnType;
  }

  Type* assertOrReturnBinaryType(BinaryExpr& expr, Type* type) {
    return ::assertOrReturnBinaryType(expr, type, type);
  }
}

void TypeCheckVisitor::visit(AddExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(AndExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getBoolType());
}

void TypeCheckVisitor::visit(BinaryValExpr& expr) {
  result = getBoolType();
}

void TypeCheckVisitor::visit(DivExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getBoolType());
}

void TypeCheckVisitor::visit(EqualExpr& expr) {
  result = ::assertOrReturnBinarySameType(expr, getBoolType());
}

void TypeCheckVisitor::visit(GreaterThanEqualExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getIntType(), getBoolType());
}

void TypeCheckVisitor::visit(GreaterThanExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getIntType(), getBoolType());
}

void TypeCheckVisitor::visit(IntegerValExpr& expr) {
  result = getIntType();
}

void TypeCheckVisitor::visit(LessThanEqualExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getIntType(), getBoolType());
}

void TypeCheckVisitor::visit(LessThanExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getIntType(), getBoolType());
}

void TypeCheckVisitor::visit(ModExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(MultiExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(NegationExpr& expr) {
  result = ::assertOrReturnUnuaryType(expr, getBoolType());
}

void TypeCheckVisitor::visit(NegExpr& expr) {
  result = ::assertOrReturnUnuaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(NotEqualExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getBoolType());
}

void TypeCheckVisitor::visit(OrExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getBoolType());
}

void TypeCheckVisitor::visit(PosExpr& expr) {
  result = ::assertOrReturnUnuaryType(expr, getIntType());
}

void TypeCheckVisitor::visit(SubExpr& expr) {
  result = ::assertOrReturnBinaryType(expr, getIntType());
}
