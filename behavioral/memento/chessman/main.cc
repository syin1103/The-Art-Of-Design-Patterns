// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "chessman.h"

int main() {
  Chessman chess("Ju", 1, 1);
  ChessPlay::Play(chess);

  chess.set_y(4);
  ChessPlay::Play(chess);

  chess.set_x(5);
  ChessPlay::Play(chess);

  ChessPlay::Undo(chess, ChessPlay::index());
  ChessPlay::Undo(chess, ChessPlay::index());
  ChessPlay::Redo(chess, ChessPlay::index());
  ChessPlay::Redo(chess, ChessPlay::index());

  return 0;
}