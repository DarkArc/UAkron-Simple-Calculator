#ifndef SUBEXPR_HPP
#define SUBEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 - e2
struct SubExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
