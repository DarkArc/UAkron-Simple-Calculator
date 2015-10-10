// The defined Expr AST represetation
//
// e ::= e1 + e2
//       e1 && e2
//       e1 / e2
//       e1 == e2
//       e1 >= e2
//       e1 > e2
//       e1 <= e2
//       e1 < e2
//       e1 % e2
//       e1 * e2
//       !e
//       -e
//       e1 != e2
//       e1 || e2
//       +e
//       e1 - e2
//       (0 | 1 | 2 | ... | 9)+

#include "AddExpr.hpp"
#include "AndExpr.hpp"
#include "Digits.hpp"
#include "DivExpr.hpp"
#include "EqualsExpr.hpp"
#include "GreaterThanEqualExpr.hpp"
#include "GreaterThanExpr.hpp"
#include "LessThanEqualExpr.hpp"
#include "LessThanEqual.hpp"
#include "ModExpr.hpp"
#include "MultiExpr.hpp"
#include "NegationExpr.hpp"
#include "NegExpr.hpp"
#include "NotEqualsExpr.hpp"
#include "OrExpr.hpp"
#include "PosExpr.hpp"
#include "SubExpr.hpp"

// Base classes to facilitate simplification of the
// implementation
#include "Expr.hpp"
#include "BinaryExpr.hpp"
#include "UnaryExpr.hpp"
