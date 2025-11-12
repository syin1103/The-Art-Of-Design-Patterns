// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_COMMAND_CACULATOR_COMMAND_H_
#define BEHAVIORAL_COMMAND_CACULATOR_COMMAND_H_

#include <memory>
#include <stack>

#include "caculator.h"

class Command {
 public:
  Command() = default;
  virtual ~Command() = default;
  virtual double Execute() = 0;
  virtual double Undo() = 0;
};

class AddCommand : public Command {
 public:
  AddCommand(Caculator& calc, double value) : calc_(calc), value_(value) {}
  virtual ~AddCommand() = default;

  double Execute() override {
    prev_ = calc_.value();
    return calc_.Add(value_);
  }

  double Undo() override {
    calc_.set_value(prev_);
    return prev_;
  }

 private:
  Caculator& calc_;
  double prev_ = 0.0;
  double value_;
};

class SubtractCommand : public Command {
 public:
  SubtractCommand(Caculator& calc, double value) : calc_(calc), value_(value) {}
  virtual ~SubtractCommand() = default;

  double Execute() override {
    prev_ = calc_.value();
    return calc_.Subtract(value_);
  }

  double Undo() override {
    calc_.set_value(prev_);
    return prev_;
  }

 private:
  Caculator& calc_;
  double prev_ = 0.0;
  double value_;
};

class CommandManager {
 public:
  double ExecuteCommand(std::unique_ptr<Command> command) {
    double value = command->Execute();
    undo_stk_.push(std::move(command));
    ClearStack(redo_stk_);
    return value;
  }

  double Undo() {
    if (undo_stk_.empty()) {
      std::cout << "Has not Undo Operation..." << std::endl;
      return -1;
    }

    std::unique_ptr<Command> command = std::move(undo_stk_.top());
    double value = command->Undo();
    undo_stk_.pop();
    redo_stk_.push(std::move(command));
    return value;
  }

  double Redo() {
    if (redo_stk_.empty()) {
      std::cout << "Has not Redo Operation..." << std::endl;
      return -1;
    }

    std::unique_ptr<Command> command = std::move(redo_stk_.top());
    double value = command->Execute();
    redo_stk_.pop();
    undo_stk_.push(std::move(command));
    return value;
  }

 private:
  void ClearStack(std::stack<std::unique_ptr<Command>>& stk) {
    if (!stk.empty()) {
      std::stack<std::unique_ptr<Command>> empty_stk;
      stk.swap(empty_stk);
    }
  }

  std::stack<std::unique_ptr<Command>> undo_stk_;
  std::stack<std::unique_ptr<Command>> redo_stk_;
};

#endif  // BEHAVIORAL_COMMAND_CACULATOR_COMMAND_H_