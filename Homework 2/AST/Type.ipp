Type::~Type() { }

BoolType* getBoolType() {
  static BoolType type;
  return &type;
}

IntType* getIntType() {
  static IntType type;
  return &type;
}
