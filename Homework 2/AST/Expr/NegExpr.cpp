#include "NegExpr.hpp"

void NegExpr::accept(Visitor& v) {
  v.visit(*this);
}
