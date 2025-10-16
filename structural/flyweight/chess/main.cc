// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <string>

#include "igo_chess.h"
#include "igo_chess_factory.h"

int main() {
  auto factory = IgoChessFactory::Instance();
  auto black1 = factory.Create("black");
  auto black2 = factory.Create("black");
  auto white1 = factory.Create("white");
  auto white2 = factory.Create("white");

  std::cout << "Black chess are same: " << (black1 == black2) << std::endl;
  std::cout << "White chess are same: " << (white1 == white2) << std::endl;

  black1->Display(Coordinates(1, 2));
  white1->Display(Coordinates(3, 4));

  return 0;
}