#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

struct Parser {
  std::string la;

  void next();
};

#endif
