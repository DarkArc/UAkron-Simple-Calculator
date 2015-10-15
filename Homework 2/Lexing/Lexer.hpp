#ifndef LEXER_HPP
#define LEXER_HPP

#include "Token.hpp"

#include <vector>
#include <iosfwd>

struct Lexer {

};

std::vector<token> tokenize(std::istream input);

#include "Lexer.ipp"

#endif
