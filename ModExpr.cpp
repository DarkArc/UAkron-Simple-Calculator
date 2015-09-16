#include "ModExpr.hpp"

void ModExpr::accept(Visitor& v) {
  v.visit(*this);
}
