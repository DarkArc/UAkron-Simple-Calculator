cmake_minimum_required(VERSION 3.1)

# Project Declaration
project(CalcLAngCore CXX)

# Source Declaration
add_executable(CalcLangCore
  AddExpr.cpp
  BinaryExpr.cpp
  Digit.cpp
  DivExpr.cpp
  EvalVisitor.cpp
  Expr.cpp
  ModExpr.cpp
  MultiExpr.cpp
  SubExpr.cpp
  TestMain.cpp
)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
