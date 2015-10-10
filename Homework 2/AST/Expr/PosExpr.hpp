#ifndef POSEXPR_HPP
#define POSEXPR_HPP

#include "UnaryExpr.hpp"

// Representative of the AST production:
// e ::= +e
struct PosExpr : public UnaryExpr {
  using UnaryExpr::UnaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
