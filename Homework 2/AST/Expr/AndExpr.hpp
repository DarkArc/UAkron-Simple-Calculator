#ifndef ANDEXPR_HPP
#define ANDEXPR_HPP

#include "BinaryExpr.hpp"

// Representative of the AST production:
// e ::= e1 && e2
struct AndExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
