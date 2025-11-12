// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_MENU_COMMAND_H_
#define BEHAVIORAL_MENU_COMMAND_H_

#include <string>

#include "board_screen.h"

class Command {
 public:
  virtual void Execute() = 0;
  virtual std::string GetDescription() const = 0;
};

class OpenCommand : public Command {
 public:
  OpenCommand(BoardScreen& screen) : screen_(screen) {}

  void Execute() override { screen_.Open(); }
  std::string GetDescription() const override { return "Open Command"; }

 private:
  BoardScreen& screen_;
};

class CreateCommand : public Command {
 public:
  CreateCommand(BoardScreen& screen) : screen_(screen) {}

  void Execute() override { screen_.Create(); }
  std::string GetDescription() const override { return "Create Command"; }

 private:
  BoardScreen& screen_;
};

class EditCommand : public Command {
 public:
  EditCommand(BoardScreen& screen) : screen_(screen) {}

  void Execute() override { screen_.Edit(); }
  std::string GetDescription() const override { return "Edit Command"; }

 private:
  BoardScreen& screen_;
};

#endif  // BEHAVIORAL_MENU_COMMAND_H_