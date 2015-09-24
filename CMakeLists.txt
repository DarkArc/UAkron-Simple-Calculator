cmake_minimum_required(VERSION 3.1)

# Project Declaration
project(CalcLangLib CXX)
project(CalcEvalLib CXX)
project(CalcSExprLib CXX)
project(CalcPostfixLib CXX)

project(CalcEval CXX)
project(CalcSExpr CXX)
project(CalcPostfix CXX)


# Core Library
file(GLOB core_lib_SRC
    "Expr/*.cpp"
    "Parser/*.cpp"
)

add_library(CalcLangLib
  ${core_lib_SRC}
)

# Eval Library
file(GLOB eval_lib_SRC
    "Eval/lib/*.cpp"
)

add_library(CalcEvalLib
  ${eval_lib_SRC}
)

# SExpr Library
file(GLOB sexpr_lib_SRC
    "SExpr/lib/*.cpp"
)

add_library(CalcSExprLib
  ${sexpr_lib_SRC}
)

# Postfix Library
file(GLOB postfix_lib_SRC
    "Postfix/lib/*.cpp"
)

add_library(CalcPostfixLib
  ${postfix_lib_SRC}
)

# Evaluation Program
file(GLOB eval_SRC
    "Eval/*.cpp"
)

add_executable(CalcEval
  ${eval_SRC}
)

target_link_libraries(CalcEval CalcLangLib CalcEvalLib)

# SExpr Program
file(GLOB sExpr_SRC
    "SExpr/*.cpp"
)

add_executable(CalcSExpr
  ${sExpr_SRC}
)

target_link_libraries(CalcSExpr CalcLangLib CalcSExprLib)

# Postfix Program
file(GLOB postfix_SRC
    "Postfix/*.cpp"
)

add_executable(CalcPostfix
  ${postfix_SRC}
)

target_link_libraries(CalcPostfix CalcLangLib CalcPostfixLib)

# Test suite
file(GLOB test_SRC
    "Test/*.cpp"
)

add_executable(CalcTest
  ${test_SRC}
)

target_link_libraries(CalcTest CalcLangLib CalcEvalLib CalcSExprLib CalcPostfixLib)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")
