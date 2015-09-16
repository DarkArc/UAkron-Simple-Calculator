#ifndef EXPR_HPP
#define EXPR_HPP

#include "Visitor.hpp"

struct Expr {
  virtual ~Expr();
  virtual void accept(Visitor&) = 0;
};

#endif
