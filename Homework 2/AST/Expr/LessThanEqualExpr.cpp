#include "LessThanEqualExpr.hpp"

void LessThanEqualExpr::accept(Visitor& v) {
  v.visit(*this);
}
