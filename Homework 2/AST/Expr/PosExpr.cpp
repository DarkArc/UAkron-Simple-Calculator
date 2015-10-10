#include "PosExpr.hpp"

void PosExpr::accept(Visitor& v) {
  v.visit(*this);
}
