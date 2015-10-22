inline
Type::~Type() { }

inline BoolType*
getBoolType() {
  static BoolType type;
  return &type;
}

inline IntType*
getIntType() {
  static IntType type;
  return &type;
}
