#ifndef LESSTHANEQUALEXPR_HPP
#define LESSTHANEQUALEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 <= e2
struct LessThanEqualExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
