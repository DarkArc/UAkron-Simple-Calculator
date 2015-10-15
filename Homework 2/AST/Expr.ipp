inline
Expr::~Expr() { }

inline
UnaryExpr::UnaryExpr(Expr& expr) : expr(&expr) { }

inline
BinaryExpr::BinaryExpr(Expr& leftExpr, Expr& rightExpr) : leftExpr(&leftExpr), rightExpr(&rightExpr) { }

inline void
AddExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
AndExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline
Digits::Digits(const int& val) : val(val) { }

inline void
Digits::accept(Visitor& v) {
  v.visit(*this);
}

inline void
DivExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
EqualsExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
GreaterThanEqualExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
GreaterThanExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
LessThanEqualExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
LessThanExpr::accept(Visitor& v) {
  v.visit(*this);
}
inline void
ModExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
MultiExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
NegationExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
NegExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
NotEqualsExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
OrExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
PosExpr::accept(Visitor& v) {
  v.visit(*this);
}

inline void
SubExpr::accept(Visitor& v) {
  v.visit(*this);
}
