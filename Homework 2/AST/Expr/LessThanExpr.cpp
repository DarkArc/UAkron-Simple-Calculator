#include "LessThanExpr.hpp"

void LessThanExpr::accept(Visitor& v) {
  v.visit(*this);
}
