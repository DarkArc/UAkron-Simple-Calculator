#ifndef UNARYEXPR_HPP
#define UNARYEXPR_HPP

#include "Expr.hpp"

// Base class representing any unary expression on the AST
struct UnaryExpr : public Expr {
  Expr* expr;

  UnaryExpr(Expr&);
};

#endif
