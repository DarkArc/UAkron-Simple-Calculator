#ifndef ADDEXPR_HPP
#define ADDEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 + e2
struct AddExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
