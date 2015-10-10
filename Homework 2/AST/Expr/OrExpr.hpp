#ifndef OREXPR_HPP
#define OREXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 || e2
struct OrExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
