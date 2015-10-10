#include "NegationExpr.hpp"

void NegationExpr::accept(Visitor& v) {
  v.visit(*this);
}
