#ifndef EVALVISITOR_HPP
#define EVALVISITOR_HPP

#include "../Expr/Expr.hpp"
#include "../Visitor.hpp"

struct EvalVisitor : public Visitor {
  int result = 0;

  virtual void visit(AddExpr&);
  virtual void visit(Digit&);
  virtual void visit(DivExpr&);
  virtual void visit(ModExpr&);
  virtual void visit(MultiExpr&);
  virtual void visit(SubExpr&);
};

inline int eval(Expr& e) {
  EvalVisitor v;
  e.accept(v);
  return v.result;
}

inline int eval(Expr* e) {
  return eval(*e);
}

#endif
