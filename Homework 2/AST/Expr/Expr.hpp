#ifndef EXPR_HPP
#define EXPR_HPP

#include "../../Visitor.hpp"
#include "../Type/Type.hpp"

// Base class representing any expression on the AST
struct Expr {
  Type* type = nullptr;

  virtual ~Expr();
  virtual void accept(Visitor&) = 0;
};

#endif
