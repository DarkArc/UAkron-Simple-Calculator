#include "DivExpr.hpp"

void DivExpr::accept(Visitor& v) {
  v.visit(*this);
}
