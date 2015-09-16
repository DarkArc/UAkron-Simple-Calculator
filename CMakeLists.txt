cmake_minimum_required(VERSION 3.1)

# Project Declaration
project(CalcLAngCore CXX)

file(GLOB expr_SRC
    "Expr/*.cpp"
)

# Source Declaration
add_library(CalcLangCore
  ${expr_SRC}
)

add_executable(CalcEval
  EvalVisitor.cpp
  TestMain.cpp
)

target_link_libraries(CalcEval CalcLangCore)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
