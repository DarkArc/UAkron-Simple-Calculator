inline Type* typeCheck(Expr& e) {
  TypeCheckVisitor v;
  e.accept(v);
  return e.type = v.result;
}

inline Type* typeCheck(Expr* e) {
  return typeCheck(*e);
}
