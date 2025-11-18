// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <memory>

#include "ally.h"

int main() {
  AllyControlCenter control;

  auto player1 = std::make_shared<Player>("Jack");
  auto player2 = std::make_shared<Player>("Tom");
  auto player3 = std::make_shared<Player>("Lucy");

  control.Attach(player1);
  control.Attach(player2);
  control.Attach(player3);

  player1->BeAttacked(control);
  return 0;
}