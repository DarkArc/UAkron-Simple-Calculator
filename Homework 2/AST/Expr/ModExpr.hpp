#ifndef MODEXPR_HPP
#define MODEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 % e2
struct ModExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
