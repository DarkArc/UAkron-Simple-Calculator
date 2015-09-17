cmake_minimum_required(VERSION 3.1)

# Project Declaration
project(CalcLangCore CXX)
project(CalcEval CXX)


# Core Library
file(GLOB expr_SRC
    "Expr/*.cpp"
)

add_library(CalcLangCore
  ${expr_SRC}
)

# Evaluation Program
file(GLOB eval_SRC
    "Eval/*.cpp"
)

add_executable(CalcEval
  ${eval_SRC}
)

target_link_libraries(CalcEval CalcLangCore)

# SExpr Program
file(GLOB sExpr_SRC
    "SExpr/*.cpp"
)

add_executable(CalcSExpr
  ${sExpr_SRC}
)

target_link_libraries(CalcSExpr CalcLangCore)

# Postfix Program
file(GLOB postfix_SRC
    "Postfix/*.cpp"
)

add_executable(CalcPostfix
  ${postfix_SRC}
)

target_link_libraries(CalcPostfix CalcLangCore)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
