#pragma once

#include "../AST/Expr.hpp"
#include "../AST/Type.hpp"
#include "../Visitor.hpp"

struct TypeCheckVisitor : public Visitor {
  Type* result = nullptr;

  virtual void visit(AddExpr&) override;
  virtual void visit(AndExpr&) override;
  virtual void visit(BinaryValExpr&) override;
  virtual void visit(DivExpr&) override;
  virtual void visit(EqualExpr&) override;
  virtual void visit(GreaterThanEqualExpr&) override;
  virtual void visit(GreaterThanExpr&) override;
  virtual void visit(IntegerValExpr&) override;
  virtual void visit(LessThanEqualExpr&) override;
  virtual void visit(LessThanExpr&) override;
  virtual void visit(ModExpr&) override;
  virtual void visit(MultiExpr&) override;
  virtual void visit(NegationExpr&) override;
  virtual void visit(NegExpr&) override;
  virtual void visit(NotEqualExpr&) override;
  virtual void visit(OrExpr&) override;
  virtual void visit(PosExpr&) override;
  virtual void visit(SubExpr&) override;
};

inline Type* typeCheck(Expr& e) {
  TypeCheckVisitor v;
  e.accept(v);
  return v.result;
}

inline Type* typeCheck(Expr* e) {
  return typeCheck(*e);
}

#include "TypeChecker.ipp"
