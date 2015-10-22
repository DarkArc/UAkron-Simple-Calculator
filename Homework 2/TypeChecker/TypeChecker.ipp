inline Type* typeCheck(Expr& e) {
  TypeCheckVisitor v;
  e.accept(v);
  return v.result;
}

inline Type* typeCheck(Expr* e) {
  return typeCheck(*e);
}
