#ifndef VISITOR_HPP
#define VISITOR_HPP

class AddExpr;
class AndExpr;
class BinaryValExpr;
class DivExpr;
class EqualExpr;
class GreaterThanEqualExpr;
class GreaterThanExpr;
class IntegerValExpr;
class LessThanEqualExpr;
class LessThanExpr;
class ModExpr;
class MultiExpr;
class NegationExpr;
class NegExpr;
class NotEqualExpr;
class OrExpr;
class PosExpr;
class SubExpr;

struct Visitor {
  virtual ~Visitor();

  virtual void visit(AddExpr&) = 0;
  virtual void visit(AndExpr&) = 0;
  virtual void visit(BinaryValExpr&) = 0;
  virtual void visit(DivExpr&) = 0;
  virtual void visit(EqualExpr&) = 0;
  virtual void visit(GreaterThanEqualExpr&) = 0;
  virtual void visit(GreaterThanExpr&) = 0;
  virtual void visit(IntegerValExpr&) = 0;
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
