#ifndef SEXPRVISITOR_HPP
#define SEXPRVISITOR_HPP

#include "../Expr/Expr.hpp"
#include "../Visitor.hpp"

#include <string>

struct SExprVisitor : public Visitor {
  std::string result = "";

  virtual void visit(AddExpr&);
  virtual void visit(Digit&);
  virtual void visit(DivExpr&);
  virtual void visit(ModExpr&);
  virtual void visit(MultiExpr&);
  virtual void visit(SubExpr&);
};

inline std::string eval(Expr& e) {
  SExprVisitor v;
  e.accept(v);
  return v.result;
}

inline std::string eval(Expr* e) {
  return eval(*e);
}

#endif
