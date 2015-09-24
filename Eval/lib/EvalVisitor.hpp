#ifndef EVALVISITOR_HPP
#define EVALVISITOR_HPP

#include "../../Expr/Expr.hpp"
#include "../../Visitor.hpp"

namespace EvalLib {

struct EvalVisitor : public Visitor {
  int result = 0;

  virtual void visit(AddExpr&) override;
  virtual void visit(Digit&) override;
  virtual void visit(DivExpr&) override;
  virtual void visit(ModExpr&) override;
  virtual void visit(MultiExpr&) override;
  virtual void visit(SubExpr&) override;
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
