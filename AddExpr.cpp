#include "AddExpr.hpp"

void AddExpr::accept(Visitor& v) {
  v.visit(*this);
}
