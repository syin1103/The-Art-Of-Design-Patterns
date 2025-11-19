// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "player.h"

int main() {
  Player player;

  player.Play();

  player.Win(1500);
  player.DoubleScore();

  player.Win(1000);
  player.ChangeCards();

  player.Win(2000);
  player.PeekCards();
  return 0;
}