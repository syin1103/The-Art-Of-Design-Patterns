// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_BUILDER_PLAYER_INTERFACE_BUILDER_H_
#define CREATIONAL_BUILDER_PLAYER_INTERFACE_BUILDER_H_

#include "interface.h"

class InterfaceBuilder {
 public:
  InterfaceBuilder() = default;
  ~InterfaceBuilder() = default;

  InterfaceBuilder& ShowMenu(bool flag) {
    interface_.set_show_menu(flag);
    return *this;
  }

  InterfaceBuilder& PlayList(bool flag) {
    interface_.set_play_list(flag);
    return *this;
  }

  InterfaceBuilder& Mainwindow(bool flag) {
    interface_.set_mainwindow(flag);
    return *this;
  }

  InterfaceBuilder& ControlBar(bool flag) {
    interface_.set_control_bar(flag);
    return *this;
  }

  Interface Build() { return std::move(interface_); }

 private:
  Interface interface_{};
};

#endif  // CREATIONAL_BUILDER_PLAYER_INTERFACE_BUILDER_H_