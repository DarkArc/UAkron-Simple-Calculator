#ifndef NOTEQUALEXPR_HPP
#define NOTEQUALEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 != e2
struct NotEqualExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
