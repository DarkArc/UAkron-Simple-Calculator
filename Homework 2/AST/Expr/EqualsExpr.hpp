#ifndef EQUALSEXPR_HPP
#define EQUALSEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 == e2
struct EqualsExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
