#ifndef DIGITS_HPP
#define DIGITS_HPP

#include "Expr.hpp"

// Base class representing any binary expression on the AST
// e ::= (0 | 1 | 2 | ... | 9)+
struct Digits : public Expr {
  int val;

  Digits(const int&);

  virtual void accept(Visitor&) override;
};

#endif
