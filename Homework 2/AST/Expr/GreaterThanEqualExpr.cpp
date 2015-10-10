#include "GreaterThanEqualExpr.hpp"

void GreaterThanEqualExpr::accept(Visitor& v) {
  v.visit(*this);
}
