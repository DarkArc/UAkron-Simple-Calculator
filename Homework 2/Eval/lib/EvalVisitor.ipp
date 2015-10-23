namespace EvalLib {

inline EvalValue
eval(Expr& e) {
  EvalVisitor v;
  e.accept(v);
  return {v.resultType, v.result};
}

inline EvalValue
eval(Expr* e) {
  return eval(*e);
}

}
