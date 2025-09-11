// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "interface.h"

#include <iostream>

#include "interface_builder.h"

int main() {
  Interface complete = InterfaceBuilder()
                           .ShowMenu(true)
                           .Mainwindow(true)
                           .PlayList(true)
                           .ControlBar(true)
                           .Build();

  Interface lite = InterfaceBuilder().Mainwindow(true).ControlBar(true).Build();
  Interface memory = InterfaceBuilder()
                         .Mainwindow(true)
                         .ControlBar(true)
                         .PlayList(true)
                         .Build();

  std::cout << "Complete Mode: " << complete.show_menu() << ", "
            << complete.play_list() << ", " << complete.mainwindow() << ", "
            << complete.control_bar() << std::endl;

  std::cout << "Lite Mode: " << lite.show_menu() << ", " << lite.play_list()
            << ", " << lite.mainwindow() << ", " << lite.control_bar()
            << std::endl;

  std::cout << "Memory Mode: " << memory.show_menu() << ", "
            << memory.play_list() << ", " << memory.mainwindow() << ", "
            << memory.control_bar() << std::endl;
  return 0;
}