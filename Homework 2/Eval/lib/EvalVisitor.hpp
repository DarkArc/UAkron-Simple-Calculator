#ifndef EVALVISITOR_HPP
#define EVALVISITOR_HPP

#include "../../AST/Expr/Expr.hpp"
#include "../../Visitor.hpp"

namespace EvalLib {

struct EvalVisitor : public Visitor {
  int result = 0;

  virtual void visit(AddExpr&) override;
  virtual void visit(AndExpr&) override;
  virtual void visit(Digits&) override;
  virtual void visit(DivExpr&) override;
  virtual void visit(EqualsExpr&) override;
  virtual void visit(GreaterThanEqualExpr&) override;
  virtual void visit(GreaterThanExpr&) override;
  virtual void visit(LessThanEqualExpr&) override;
  virtual void visit(LessThanExpr&) override;
  virtual void visit(ModExpr&) override;
  virtual void visit(MultiExpr&) override;
  virtual void visit(NegationExpr&) override;
  virtual void visit(NegExpr&) override;
  virtual void visit(NotEqualExpr&) override;
  virtual void visit(OrExpr&) override;
  virtual void visit(PosExpr&) override;
  virtual void visit(SubExpr&) override;=
};

inline int eval(Expr& e) {
  EvalVisitor v;
  e.accept(v);
  return v.result;
}

inline int eval(Expr* e) {
  return eval(*e);
}

}

#endif
