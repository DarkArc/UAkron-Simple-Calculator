#ifndef NEGATIONEXPR_HPP
#define NEGATIONEXPR_HPP

#include "UnaryExpr.hpp"

// Representative of the AST production:
// e ::= !e
struct NegationExpr : public UnaryExpr {
  using UnaryExpr::UnaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
