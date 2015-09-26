// The defined AST represetation
//
// e ::= e1 + e2
//       e1 - e2
//       e1 * e2
//       e1 / e2
//       e1 % e2
//       (0 | 1 | 2 | ... | 9)+

#include "Expr/AddExpr.hpp"
#include "Expr/Digits.hpp"
#include "Expr/DivExpr.hpp"
#include "Expr/ModExpr.hpp"
#include "Expr/MultiExpr.hpp"
#include "Expr/SubExpr.hpp"

// Base classes to facilitate simplification of the
// implementation
#include "Expr/Expr.hpp"
#include "Expr/BinaryExpr.hpp"
