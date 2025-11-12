// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_MENU_BOARD_SCREEN_H_
#define BEHAVIORAL_MENU_BOARD_SCREEN_H_

#include <iostream>

class BoardScreen {
 public:
  void Open() { std::cout << "BoardScreen Open..." << std::endl; }
  void Create() { std::cout << "BoardScreen Create..." << std::endl; }
  void Edit() { std::cout << "BoardScreen Edit..." << std::endl; }
};

#endif  // BEHAVIORAL_MENU_BOARD_SCREEN_H_
