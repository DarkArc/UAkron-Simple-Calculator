#include "Lexer.hpp"

#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>

bool
ReparseStream::eof() {
  return reparseText.empty() && input->eof();
}

char
ReparseStream::readLA() {
  if (!reparseText.empty()) {
    char back = reparseText.back();
    reparseText.pop_back();
    return back;
  }
  return input->get();
}

void
ReparseStream::reparse(const std::string& str) {
  if (!reparseText.empty()) {
    std::runtime_error("Illegal lexer state!");
  }
  reparseText = str;
}

bool
Predictor::operator () (const std::string& str) {
  auto strCur = str.begin();

  for (auto&& aChar : prediction) {
    if (*strCur == aChar) {
      ++strCur;
    } else {
      return false;
    }
  }

  while (strCur != str.end()) {
    char aChar = stream->readLA();

    if (stream->eof()) {
      return false;
    }

    prediction += aChar;

    if (*strCur == aChar) {
      ++strCur;
    } else {
      return false;
    }
  }

  lexer->text += prediction;
  return true;
}

std::vector<Token>
Lexer::tokenize() {
  while (!input.eof()) {
    // When the predictor goes out of scope
    // if has been used, but failed to find a prediction
    // the characters will re-enter the lexer
    Predictor predict(input, *this);
    switch (char curChar = readLA()) {
      case ' ':
      case '\t':
      case '\n':
        text.pop_back();
        break;
      case '(':
        addTok(TokType::L_PAREN, predict);
        break;
      case ')':
        addTok(TokType::R_PAREN, predict);
        break;
      case '+':
        addTok(TokType::PLUS, predict);
        break;
      case '-':
        addTok(TokType::MINUS, predict);
        break;
      case '*':
        addTok(TokType::STAR, predict);
        break;
      case '/':
        addTok(TokType::SLASH, predict);
        break;
      case '%':
        addTok(TokType::PERCENT, predict);
        break;
      case 't':
        if (predict("rue")) {
          addTok(TokType::KW_TRUE, predict);
          break;
        }
        break;
      case 'f':
        if (predict("alse")) {
          addTok(TokType::KW_FALSE, predict);
          break;
        }
        break;
      case '&':
        if (predict("&")) {
          addTok(TokType::AND, predict);
          break;
        }
        break;
      case '|':
        if (predict("|")) {
          addTok(TokType::OR, predict);
          break;
        }
        break;
      case '!':
        if (predict("=")) {
          addTok(TokType::NOT_EQ, predict);
          break;
        }
        addOrigTok(TokType::NOT, predict);
        break;
      case '=':
        if (predict("=")) {
          addTok(TokType::EQUAL, predict);
          break;
        }
        break;
      case '<':
        if (predict("=")) {
          addTok(TokType::LESS_THAN_EQ, predict);
          break;
        }
        addOrigTok(TokType::LESS_THAN, predict);
        break;
      case '>':
        if (predict("=")) {
          addTok(TokType::GREATHER_THAN_EQ, predict);
          break;
        }
        addOrigTok(TokType::GREATER_THAN, predict);
      default:
        if (std::isdigit(curChar)) {
          consumeInt(curChar, predict);
          break;
        }
        // TODO complain
    }
  }
  return out;
}

void
Lexer::consumeInt(char& curChar, Predictor& predict) {
  while (!input.eof() && std::isdigit(curChar = readLA())) { }

  text.pop_back();
  input.reparse({curChar});

  addTok(TokType::INT, predict);
}
