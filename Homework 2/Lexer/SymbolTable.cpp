#include "SymbolTable.hpp"

using MapType = SymbolTable::MapType;
using InsertReturnType = SymbolTable::InsertReturnType;

InsertReturnType
SymbolTable::insert(const MapType::value_type& val) {
  return symbols.insert(val);
}
