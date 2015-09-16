#ifndef DIGIT_HPP
#define DIGIT_HPP

#include "Expr.hpp"

struct Digit : public Expr {
  int val;

  Digit(const int&);

  virtual void accept(Visitor&) override;
};

#endif
