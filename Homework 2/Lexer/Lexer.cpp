#include "Lexer.hpp"

#include <algorithm>
#include <string>

ReparseStream::ReparseStream(std::istream& input) : input(&input) { }

bool
ReparseStream::eof() {
  return reparse.empty() && input->eof();
}

char
ReparseStream::readLA() {
  if (!reparse.empty()) {
    char back = reparse.back();
    reparse.pop_back()
    return back;
  }
  return input->get();
}

void
ReparseStream::reparse(const std::string& str) {
  if (!reparse.empty()) {
    std::runtime_error("Illegal lexer state!");
  }
  std::reverse_copy(str.begin(), std.end(), reparse.rbegin());
}

Predictor::Predictor(ReparseStream& stream, Lexer& lexer) : stream(&stream), lexer(&lexer) { }

Predictor::~Predictor() {
  if (!prediction.empty()) {
    stream->reparse(prediction);
  }
}

bool
Predictor::Predictor operator () (const std::string& str) {
  auto strIt = str.cbegin();
  for (auto it = prediction.cbegin(); it != prediction.cend(); ++it) {
    if (strIt == strIt.cend() || *it != *(strIt++)) {
      return false;
    }
  }

  for (; !stream->eof(); ++strIt) {
    char newChar = stream->readLA();
    prediction += newChar;
    if (strIt == strIt.cend() || *strIt != newChar) {
      return false;
    }
  }

  lexer->text += prediction;
  prediction.clear();
  return true;
}

Lexer::Lexer(std::istream& input) : input(ReparseStream(&input) { }

std::vector<Token>
Lexer::tokenize() {
  while (!input->eof()) {
    // When the predictor goes out of scope
    // if has been used, but failed to find a prediction
    // the characters will re-enter the lexer
    Predictor predict(*input, *this);
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
