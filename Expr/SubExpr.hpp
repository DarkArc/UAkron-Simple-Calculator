#ifndef SUBEXPR_HPP
#define SUBEXPR_HPP

#include "BinaryExpr.hpp"

struct SubExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
