// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_INTERPRETER_FORMAT_NODE_H_
#define BEHAVIORAL_INTERPRETER_FORMAT_NODE_H_

#include <iostream>
#include <memory>
#include <vector>

#include "context.h"

class Node {
 public:
  virtual void Interpret(Context& ctx) {}
  virtual void Execute() {}
};

class PrimitiveCommandNode : public Node {
 public:
  void Interpret(Context& ctx) override {
    std::string token = ctx.CurrToken();
    if (token != "PRINT" && token != "SPACE" && token != "BREAK") {
      throw std::runtime_error("Interpret error: " + token);
    }
    operation_ = token;
    ctx.SkipToken(operation_);

    if (operation_ == "PRINT") {
      text_ = ctx.CurrToken();
      ctx.NextToken();
    }
  }

  void Execute() override {
    if (operation_ == "PRINT") {
      std::cout << text_;
    } else if (operation_ == "BREAK") {
      std::cout << std::endl;
    } else if (operation_ == "SPACE") {
      std::cout << " ";
    }
  }

 private:
  std::string operation_ = "";
  std::string text_ = "";
};

class ExpressionCommandNode : public Node {
 public:
  void Interpret(Context& ctx) override;

  void Execute() override {
    for (auto& cmd : commands_) {
      cmd->Execute();
    }
  }

 private:
  std::vector<std::unique_ptr<Node>> commands_;
};

class LoopCommandNode : public Node {
 public:
  void Interpret(Context& ctx) override {
    ctx.SkipToken("LOOP");
    number_ = ctx.CurrTokenToNumber();
    ctx.NextToken();
    exp_ = std::make_unique<ExpressionCommandNode>();
    exp_->Interpret(ctx);
  }

  void Execute() override {
    for (int i = 0; i < number_; i++) {
      exp_->Execute();
    }
  }

 private:
  int number_ = 0;
  std::unique_ptr<Node> exp_ = nullptr;
};

class CommandNode : public Node {
 public:
  void Interpret(Context& ctx) override {
    if (ctx.CurrToken() == "LOOP") {
      cmd_ = std::make_unique<LoopCommandNode>();
      cmd_->Interpret(ctx);
    } else {
      cmd_ = std::make_unique<PrimitiveCommandNode>();
      cmd_->Interpret(ctx);
    }
  }

  void Execute() override { cmd_->Execute(); }

 private:
  std::unique_ptr<Node> cmd_ = nullptr;
};

inline void ExpressionCommandNode::Interpret(Context& ctx) {
  while (true) {
    if (ctx.IsEnd()) {
      break;
    } else if (ctx.CurrToken() == "END") {
      ctx.SkipToken("END");
      break;
    } else {
      auto cmd_node = std::make_unique<CommandNode>();
      cmd_node->Interpret(ctx);
      commands_.emplace_back(std::move(cmd_node));
    }
  }
}

#endif  // BEHAVIORAL_INTERPRETER_FORMAT_NODE_H_