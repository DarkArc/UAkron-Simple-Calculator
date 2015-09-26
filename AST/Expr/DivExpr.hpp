#ifndef DIVEXPR_HPP
#define DIVEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 / e2
struct DivExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
