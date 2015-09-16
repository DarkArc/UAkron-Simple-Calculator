#ifndef BINARYEXPR_HPP
#define BINARYEXPR_HPP

#include "Expr.hpp"

struct BinaryExpr : public Expr {
  Expr* leftExpr;
  Expr* rightExpr;

  BinaryExpr(Expr&, Expr&);
};

#endif
