// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "board_screen.h"
#include "command.h"
#include "menu.h"

int main() {
  BoardScreen screen;

  auto open_cmd = std::make_unique<OpenCommand>(screen);
  auto create_cmd = std::make_unique<CreateCommand>(screen);
  auto edit_cmd = std::make_unique<EditCommand>(screen);

  auto open_item = std::make_unique<MenuItem>(std::move(open_cmd));
  auto create_item = std::make_unique<MenuItem>(std::move(create_cmd));
  auto edit_item = std::make_unique<MenuItem>(std::move(edit_cmd));

  Menu menu;
  menu.AddMenuItem(std::move(open_item));
  menu.AddMenuItem(std::move(create_item));
  menu.AddMenuItem(std::move(edit_item));

  menu.Test();

  return 0;
}