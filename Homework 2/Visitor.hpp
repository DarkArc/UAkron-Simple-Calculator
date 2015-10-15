#ifndef VISITOR_HPP
#define VISITOR_HPP

struct AddExpr;
struct Digits;
struct DivExpr;
struct ModExpr;
struct MultiExpr;
struct SubExpr;

struct Visitor {
  virtual ~Visitor();

  virtual void visit(AddExpr&) = 0;
  virtual void visit(AndExpr&) = 0;
  virtual void visit(Digits&) = 0;
  virtual void visit(DivExpr&) = 0;
  virtual void visit(EqualsExpr&) = 0;
  virtual void visit(GreaterThanEqualExpr&) = 0;
  virtual void visit(GreaterThanExpr&) = 0;
  virtual void visit(LessThanEqualExpr&) = 0;
  virtual void visit(LessThanExpr&) = 0;
  virtual void visit(ModExpr&) = 0;
  virtual void visit(MultiExpr&) = 0;
  virtual void visit(NegationExpr&) = 0;
  virtual void visit(NegExpr&) = 0;
  virtual void visit(NotEqualExpr&) = 0;
  virtual void visit(OrExpr&) = 0;
  virtual void visit(PosExpr&) = 0;
  virtual void visit(SubExpr&) = 0;
};

inline Visitor::~Visitor() { }

#endif
