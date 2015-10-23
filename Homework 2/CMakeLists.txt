cmake_minimum_required(VERSION 3.1)

# Project Declaration
project(CalcLangLib CXX)

project(CalcEval CXX)


# Core Library
file(GLOB core_lib_SRC
    "AST/*.cpp"
    "Lexer/*.cpp"
    "Parser/*.cpp"
)

add_library(CalcLangLib
  ${core_lib_SRC}
)

# Eval Library
file(GLOB eval_lib_SRC
    "Eval/lib/*.cpp"
    "TypeChecker/*.cpp"
)

add_library(CalcEvalLib
  ${eval_lib_SRC}
)

# Evaluation Program
file(GLOB eval_SRC
    "Eval/*.cpp"
)

add_executable(CalcEval
  ${eval_SRC}
)

target_link_libraries(CalcEval CalcLangLib CalcEvalLib)

set(CMAKE_CXX_FLAGS "-Wall -std=c++14")
