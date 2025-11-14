// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_INTERPRETER_FORMAT_CONTEXT_H_
#define BEHAVIORAL_INTERPRETER_FORMAT_CONTEXT_H_

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class Context {
 public:
  Context(const std::string& text) {
    Tokenize(text);
    curr_index_ = 0;
  }

  void NextToken() { ++curr_index_; }

  void SkipToken(const std::string& token) {
    if (token != CurrToken()) {
      throw std::runtime_error("Interpret error: " + token);
    }
    ++curr_index_;  // maybe out of range
  }

  bool IsEnd() const { return curr_index_ >= tokens_.size(); }

  size_t CurrIndex() const { return curr_index_; }
  std::string CurrToken() const { return tokens_[curr_index_]; }
  int CurrTokenToNumber() const { return std::stoi(tokens_[curr_index_]); }

 private:
  void Tokenize(const std::string& text) {
    std::istringstream iss(text);
    std::string token = "";
    while (iss >> token) {
      tokens_.push_back(token);
    }
  }

  size_t curr_index_;
  std::vector<std::string> tokens_;
};

#endif  // BEHAVIORAL_INTERPRETER_FORMAT_CONTEXT_H_