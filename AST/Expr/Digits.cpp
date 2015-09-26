#include "Digits.hpp"

Digits::Digits(const int& val) : val(val) { }

void Digits::accept(Visitor& v) {
  v.visit(*this);
}
