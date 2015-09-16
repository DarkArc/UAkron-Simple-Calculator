#ifndef DIVEXPR_HPP
#define DIVEXPR_HPP

#include "BinaryExpr.hpp"

struct DivExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
