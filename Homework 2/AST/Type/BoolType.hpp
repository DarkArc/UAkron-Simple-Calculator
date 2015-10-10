#ifndef BOOLTYPE_HPP
#define BOOLTYPE_HPP

#include "Type.hpp"

struct BoolType : public Type {

};

BoolType* getBoolType();

#include "BoolType.ipp"

#endif
