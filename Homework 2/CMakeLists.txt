cmake_minimum_required(VERSION 3.1)

# Project Declaration
project(CalcLangLib CXX)
project(CalcEval CXX)

# Core Library
file(GLOB calc_lib_SRC
  "AST/*.cpp"
  "Lexer/*.cpp"
  "Parser/*.cpp"
  "TypeChecker/*.cpp"
  "Eval/lib/*.cpp"
)

add_library(CalcLangLib
  ${calc_lib_SRC}
)

# Evaluation Program
file(GLOB eval_SRC
  "Eval/*.cpp"
)

add_executable(CalcEval
  ${eval_SRC}
)

target_link_libraries(CalcEval CalcLangLib)

set(CMAKE_CXX_FLAGS "-Wall -std=c++14")
