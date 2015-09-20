#ifndef VISITOR_HPP
#define VISITOR_HPP

struct AddExpr;
struct Digit;
struct DivExpr;
struct ModExpr;
struct MultiExpr;
struct SubExpr;

struct Visitor {
  virtual ~Visitor();

  virtual void visit(AddExpr&) = 0;
  virtual void visit(Digit&) = 0;
  virtual void visit(DivExpr&) = 0;
  virtual void visit(ModExpr&) = 0;
  virtual void visit(MultiExpr&) = 0;
  virtual void visit(SubExpr&) = 0;
};

inline Visitor::~Visitor() { }

#endif
