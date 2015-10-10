#include "MultiExpr.hpp"

void MultiExpr::accept(Visitor& v) {
  v.visit(*this);
}
