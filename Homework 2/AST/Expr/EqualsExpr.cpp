#include "EqualsExpr.hpp"

void EqualsExpr::accept(Visitor& v) {
  v.visit(*this);
}
