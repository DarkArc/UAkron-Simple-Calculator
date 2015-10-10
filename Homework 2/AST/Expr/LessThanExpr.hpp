#ifndef LESSTHANEXPR_HPP
#define LESSTHANEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 < e2
struct LessThanExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
