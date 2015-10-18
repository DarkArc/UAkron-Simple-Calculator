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
  std::reverse_copy(str.begin(), str.end(), reparseText.rbegin());
}

bool
Predictor::operator () (const std::string& str) {
  auto strIt = str.cbegin();
  for (auto it = prediction.cbegin(); it != prediction.cend(); ++it) {
    if (strIt == str.cend() || *it != *(strIt++)) {
      return false;
    }
  }

  for (; !stream->eof(); ++strIt) {
    char newChar = stream->readLA();
    prediction += newChar;
    if (strIt == str.cend() || *strIt != newChar) {
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
        }
        break;
      case 'f':
        if (predict("alse")) {
          addTok(TokType::KW_FALSE, predict);
        }
        break;
      case '&':
        if (predict("&")) {
          addTok(TokType::AND, predict);
        }
        break;
      case '|':
        if (predict("|")) {
          addTok(TokType::OR, predict);
        }
        break;
      case '!':
        if (predict("=")) {
          addTok(TokType::NOT_EQ, predict);
        }
        addOrigTok(TokType::NOT, predict);
        break;
      case '=':
        if (predict("=")) {
          addTok(TokType::EQUAL, predict);
        }
        break;
      case '<':
        if (predict("=")) {
          addTok(TokType::LESS_THAN_EQ, predict);
        }
        addOrigTok(TokType::LESS_THAN, predict);
        break;
      case '>':
        if (predict("=")) {
          addTok(TokType::GREATHER_THAN_EQ, predict);
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
  bool eof;
  while (!(eof = input.eof()) && std::isdigit(readLA())) { }

  // If we didn't hit the eof, we must have hit a characters
  // throw that char back into the ReparseStream
  if (!eof) {
    text.pop_back();
    input.reparse({curChar});
  }

  addTok(TokType::INT, predict);
}
