#include "NotEqualsExpr.hpp"

void NotEqualsExpr::accept(Visitor& v) {
  v.visit(*this);
}
