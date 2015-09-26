#ifndef POSTFIXVISITOR_HPP
#define POSTFIXVISITOR_HPP

#include "../../AST/Expr/Expr.hpp"
#include "../../Visitor.hpp"

#include <string>

namespace PostfixLib {

struct PostfixVisitor : public Visitor {
  std::string result = "";

  virtual void visit(AddExpr&) override;
  virtual void visit(Digits&) override;
  virtual void visit(DivExpr&) override;
  virtual void visit(ModExpr&) override;
  virtual void visit(MultiExpr&) override;
  virtual void visit(SubExpr&) override;
};

inline std::string eval(Expr& e) {
  PostfixVisitor v;
  e.accept(v);
  return v.result;
}

inline std::string eval(Expr* e) {
  return eval(*e);
}

}

#endif
