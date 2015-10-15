#pragma once

#include "../Visitor.hpp"
#include "Type.hpp"

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

// Base class representing any expression on the AST
struct Expr {
  Type* type = nullptr;

  virtual ~Expr();
  virtual void accept(Visitor&) = 0;
};

// Base class representing any unary expression on the AST
struct UnaryExpr : public Expr {
  Expr* expr;

  UnaryExpr(Expr&);
};

// Base class representing any binary expression on the AST
struct BinaryExpr : public Expr {
  Expr* leftExpr;
  Expr* rightExpr;

  BinaryExpr(Expr&, Expr&);
};

// Representative of the AST production:
// e ::= e1 + e2
struct AddExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 && e2
struct AndExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Base class representing any binary expression on the AST
// e ::= (0 | 1 | 2 | ... | 9)+
struct Digits : public Expr {
  int val;

  Digits(const int&);

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 / e2
struct DivExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 == e2
struct EqualsExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 >= e2
struct GreaterThanEqualExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 > e2
struct GreaterThanExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 <= e2
struct LessThanEqualExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 < e2
struct LessThanExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 % e2
struct ModExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 * e2
struct MultiExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= !e
struct NegationExpr : public UnaryExpr {
  using UnaryExpr::UnaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= -e
struct NegExpr : public UnaryExpr {
  using UnaryExpr::UnaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 != e2
struct NotEqualExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 || e2
struct OrExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= +e
struct PosExpr : public UnaryExpr {
  using UnaryExpr::UnaryExpr;

  virtual void accept(Visitor&) override;
};

// Representative of the AST production:
// e ::= e1 - e2
struct SubExpr : public BinaryExpr {
  using BinaryExpr::BinaryExpr;

  virtual void accept(Visitor&) override;
};

#include "Expr.ipp"
