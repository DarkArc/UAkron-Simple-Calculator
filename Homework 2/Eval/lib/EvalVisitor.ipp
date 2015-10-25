#include "../../TypeChecker/TypeChecker.hpp"

namespace EvalLib {

inline EvalValue
eval(Expr& e) {
  // Type check
  Type* type = typeCheck(e);

  // Evaluate
  EvalVisitor v;
  e.accept(v);
  return {type, v.result};
}

inline EvalValue
eval(Expr* e) {
  return eval(*e);
}

}
