#ifndef MULTIEXPR_HPP
#define MULTIEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 * e2
struct MultiExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
