#ifndef EXPR_HPP
#define EXPR_HPP

#include "../../Visitor.hpp"

// Base class representing any expression on the AST
struct Expr {
  virtual ~Expr();
  virtual void accept(Visitor&) = 0;
};

#endif
