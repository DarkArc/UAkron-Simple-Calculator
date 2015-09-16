#ifndef EVALVISITOR_HPP
#define EVALVISITOR_HPP

#include "Visitor.hpp"

struct EvalVisitor : public Visitor {
  int result = 0;

  virtual void visit(AddExpr&);
  virtual void visit(Digit&);
  virtual void visit(DivExpr&);
  virtual void visit(ModExpr&);
  virtual void visit(MultiExpr&);
  virtual void visit(SubExpr&);
};

#endif
