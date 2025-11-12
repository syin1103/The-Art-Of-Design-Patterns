// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_MENU_MENU_H_
#define BEHAVIORAL_MENU_MENU_H_

#include <memory>
#include <unordered_set>

#include "command.h"

class MenuItem {
 public:
  MenuItem(std::unique_ptr<Command> cmd = nullptr) : command_(std::move(cmd)) {}

  void set_command(std::unique_ptr<Command> cmd) { command_ = std::move(cmd); }
  void Click() {
    if (command_ != nullptr) {
      command_->Execute();
    }
  }

 private:
  std::unique_ptr<Command> command_;
};

class Menu {
 public:
  void AddMenuItem(std::unique_ptr<MenuItem> menu_item) {
    menu_items_.insert(std::move(menu_item));
  }

  void Test() {
    for (auto& item : menu_items_) {
      item->Click();
    }
  }

 private:
  std::unordered_set<std::unique_ptr<MenuItem>> menu_items_;
};

#endif  // BEHAVIORAL_MENU_MENU_H_