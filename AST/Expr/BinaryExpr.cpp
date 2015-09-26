#include "BinaryExpr.hpp"

BinaryExpr::BinaryExpr(Expr& leftExpr, Expr& rightExpr) : leftExpr(&leftExpr), rightExpr(&rightExpr) { }
