#pragma once

#include <unordered_map>

enum class TokType;

struct Symbol {
  TokType type;
  std::string s;

  Symbol(const TokType&, const std::string&);
};

struct IntValueSymbol : public Symbol {
  int value;

  IntValueSymbol(const TokType&, const std::string&, int);
};

struct SymbolTable {
  using MapType = std::unordered_map<std::string, Symbol*>;
  using InsertReturnType = std::pair<MapType::iterator, bool>;
  MapType symbols;

  InsertReturnType insert(const MapType::value_type&);
};

#include "SymbolTable.ipp"
