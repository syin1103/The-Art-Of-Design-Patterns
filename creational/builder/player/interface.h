// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_BUILDER_PLAYER_INTERFACE_H_
#define CREATIONAL_BUILDER_PLAYER_INTERFACE_H_

class InterfaceBuilder;

class Interface {
  friend class InterfaceBuilder;

 public:
  bool show_menu() const { return show_menu_; }
  bool play_list() const { return play_list_; }
  bool mainwindow() const { return mainwindow_; }
  bool control_bar() const { return control_bar_; }

 private:
  void set_show_menu(bool flag) { show_menu_ = flag; }
  void set_play_list(bool flag) { play_list_ = flag; }
  void set_mainwindow(bool flag) { mainwindow_ = flag; }
  void set_control_bar(bool flag) { control_bar_ = flag; }

  bool show_menu_ = false;
  bool play_list_ = false;
  bool mainwindow_ = false;
  bool control_bar_ = false;
};

#endif  // CREATIONAL_BUILDER_PLAYER_INTERFACE_H_