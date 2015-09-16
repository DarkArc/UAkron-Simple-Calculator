#include "SubExpr.hpp"

void SubExpr::accept(Visitor& v) {
  v.visit(*this);
}
