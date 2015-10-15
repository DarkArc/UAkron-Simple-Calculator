#pragma once

struct Type {
  virtual ~Type();
};

struct BoolType : public Type {

};

BoolType* getBoolType();

struct IntType : public Type {

};

IntType* getIntType();

#include "Type.ipp"
