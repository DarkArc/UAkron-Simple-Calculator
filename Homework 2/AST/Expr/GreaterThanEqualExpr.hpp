#ifndef GREATERTHANEQUALEXPR_HPP
#define GREATERTHANEQUALEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 >= e2
struct GreaterThanEqualExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
