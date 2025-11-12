// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_CACULATOR_CACULATOR_FORM_H_
#define BEHAVIORAL_CACULATOR_CACULATOR_FORM_H_

#include <iostream>
#include <memory>

#include "caculator.h"
#include "command.h"

class CaculatorForm {
 public:
  double Compute(std::unique_ptr<Command> cmd) {
    return cmd_manager_.ExecuteCommand(std::move(cmd));
  }

  void Undo() { std::cout << cmd_manager_.Undo() << std::endl; }
  void Redo() { std::cout << cmd_manager_.Redo() << std::endl; }

 private:
  CommandManager cmd_manager_;
};

#endif  // BEHAVIORAL_CACULATOR_CACULATOR_FORM_H_