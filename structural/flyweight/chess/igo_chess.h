// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_FLYWIGHT_CHESS_IGO_CHESS_H_
#define STRUCTURAL_FLYWIGHT_CHESS_IGO_CHESS_H_

#include <iostream>
#include <string>

class Coordinates {
 public:
  Coordinates(int x, int y) : x_(x), y_(y) {}

  int x() const { return x_; }
  void set_x(int x) { x_ = x; }

  int y() const { return y_; }
  void set_y(int y) { y_ = y; }

 private:
  int x_;
  int y_;
};

class IgoChess {
 public:
  IgoChess() = default;
  virtual ~IgoChess() = default;

  virtual std::string GetColor() = 0;
  void Display(Coordinates coordinates) {
    std::cout << "Chess corlor: " << GetColor() << ", "
              << "Position: " << coordinates.x() << ", " << coordinates.y()
              << std::endl;
  }
};

class BlackIgoChess : public IgoChess {
 public:
  BlackIgoChess() = default;
  virtual ~BlackIgoChess() = default;

  std::string GetColor() override { return "Black"; }
};

class WhiteIgoChess : public IgoChess {
 public:
  WhiteIgoChess() = default;
  virtual ~WhiteIgoChess() = default;

  std::string GetColor() override { return "White"; }
};

#endif  // STRUCTURAL_FLYWIGHT_CHESS_IGO_CHESS_H_