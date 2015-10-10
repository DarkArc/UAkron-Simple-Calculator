#ifndef NEGEXPR_HPP
#define NEGEXPR_HPP

#include "UnaryExpr.hpp"

// Representative of the AST production:
// e ::= -e
struct NegExpr : public UnaryExpr {
  using UnaryExpr::UnaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
