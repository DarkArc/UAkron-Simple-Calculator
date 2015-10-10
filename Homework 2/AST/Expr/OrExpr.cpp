#include "OrExpr.hpp"

void OrExpr::accept(Visitor& v) {
  v.visit(*this);
}
