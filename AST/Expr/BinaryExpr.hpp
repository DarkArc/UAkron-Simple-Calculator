#ifndef BINARYEXPR_HPP
#define BINARYEXPR_HPP

#include "Expr.hpp"

// Base class representing any binary expression on the AST
struct BinaryExpr : public Expr {
  Expr* leftExpr;
  Expr* rightExpr;

  BinaryExpr(Expr&, Expr&);
};

#endif
