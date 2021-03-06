#pragma once

#include "../../AST/Expr.hpp"
#include "../../Visitor.hpp"

#include <string>

namespace EvalLib {

struct EvalValue {
  Type* type;
  int value;
};

struct EvalVisitor : public Visitor {
  int result = 0;

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

std::string prettyEval(Expr* e);

EvalValue eval(Expr& e);
EvalValue eval(Expr* e);

}

#include "EvalVisitor.ipp"
