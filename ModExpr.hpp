#ifndef MODEXPR_HPP
#define MODEXPR_HPP

#include "BinaryExpr.hpp"

struct ModExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
