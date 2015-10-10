#ifndef GREATERTHANEXPR_HPP
#define GREATERTHANEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 > e2
struct GreaterThanExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
