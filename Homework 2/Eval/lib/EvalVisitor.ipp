namespace EvalLib {

inline int eval(Expr& e) {
  EvalVisitor v;
  e.accept(v);
  return v.result;
}

inline int eval(Expr* e) {
  return eval(*e);
}

}
