#include "GreaterThanExpr.hpp"

void GreaterThanExpr::accept(Visitor& v) {
  v.visit(*this);
}
