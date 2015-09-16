#ifndef ADDEXPR_HPP
#define ADDEXPR_HPP

#include "BinaryExpr.hpp"

struct AddExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#endif
