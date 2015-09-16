#include "Digit.hpp"

Digit::Digit(const int& val) : val(val) { }

void Digit::accept(Visitor& v) {
  v.visit(*this);
}
