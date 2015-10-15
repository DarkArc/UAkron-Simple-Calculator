#include "Lexer.hpp"

#include <string>

Lexer::Lexer(std::istream& input) : input(&input) { }

std::vector<Token>
Lexer::tokenize() {
  while (!input->eof()) {
    predictionCleanup();
    switch (readLA()) {
      case ' ':
      case '\t':
      case '\n':
        text.pop_back();
        break;
      case '(':
        addTok(TokType::L_PAREN);
        break;
      case ')':
        addTok(TokType::R_PAREN);
        break;
      case '+':
        addTok(TokType::PLUS);
        break;
      case '-':
        addTok(TokType::MINUS);
        break;
      case '*':
        addTok(TokType::STAR);
        break;
      case '/':
        addTok(TokType::SLASH);
        break;
      case '%':
        addTok(TokType::PERCENT);
        break;
      case 't':
        if (predict("rue")) {
          addTok(TokType::KW_TRUE);
        }
        break;
      case 'f':
        if (predict("alse")) {
          addTok(TokType::KW_FALSE);
        }
        break;
      case '&':
        if (predict("&")) {
          addTok(TokType::AND);
        }
        break;
      case '|':
        if (predict("|")) {
          addTok(TokType::OR);
        }
        break;
      case '!':
        if (predict("=")) {
          addTok(TokType::NOT_EQ);
        }
        addOrigTok(TokType::NOT);
        break;
      case '=':
        if (predict("=")) {
          addTok(TokType::EQUAL);
        }
        break;
      case '<':
        if (predict("=")) {
          addTok(TokType::LESS_THAN_EQ);
        }
        addOrigTok(TokType::LESS_THAN);
        break;
      case '>':
        if (predict("=")) {
          addTok(TokType::GREATHER_THAN_EQ);
        }
        addOrigTok(TokType::GREATER_THAN);
      default:
        // TODO numbers
    }
  }
}

bool
Lexer::predict(const std::string& str) {
  auto strIt = str.cbegin();
  for (auto it = prediction.cbegin(); it != prediction.cend(); ++it) {
    if (strIt == strIt.cend() || *it != *(strIt++)) {
      return false;
    }
  }

  for (; !input->eof(); ++strIt) {
    char newChar = readLA();
    prediction += newChar;
    if (strIt == strIt.cend() || *strIt != newChar) {
      return false;
    }
  }
  return true;
}
