#ifndef MULTIEXPR_HPP
#define MULTIEXPR_HPP

#include "BinaryExpr.hpp"

struct MultiExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
