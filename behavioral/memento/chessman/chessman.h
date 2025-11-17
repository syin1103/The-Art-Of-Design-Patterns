// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_MEMENTO_CHESSMAN_CHESSMAN_H_
#define BEHAVIORAL_MEMENTO_CHESSMAN_CHESSMAN_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Chessman;
class ChessmanMemento {
  friend Chessman;

 public:
  ChessmanMemento(const std::string& label, int x, int y)
      : label_(label), x_(x), y_(y) {}

  std::string label() const { return label_; }
  void set_label(const std::string& label) { label_ = label; }

  int x() const { return x_; }
  void set_x(int x) { x_ = x; }

  int y() const { return y_; }
  void set_y(int y) { y_ = y; }

 private:
  std::string label_;
  int x_;
  int y_;
};

class Chessman {
 public:
  Chessman(const std::string& label, int x, int y)
      : label_(label), x_(x), y_(y) {}

  std::string label() const { return label_; }
  void set_label(const std::string& label) { label_ = label; }

  int x() const { return x_; }
  void set_x(int x) { x_ = x; }

  int y() const { return y_; }
  void set_y(int y) { y_ = y; }

  std::shared_ptr<ChessmanMemento> Save() {
    return std::make_shared<ChessmanMemento>(label_, x_, y_);
  }

  void Restore(std::shared_ptr<ChessmanMemento> memento) {
    label_ = memento->label_;
    x_ = memento->x_;
    y_ = memento->y_;
  }

 private:
  std::string label_;
  int x_;
  int y_;
};

class CareTaker {
 public:
  std::shared_ptr<ChessmanMemento> GetMemento(int i) { return mementos_[i]; }
  void SetMemento(std::shared_ptr<ChessmanMemento> memento) {
    mementos_.push_back(memento);
  }

 private:
  std::vector<std::shared_ptr<ChessmanMemento>> mementos_;
};

class ChessPlay {
 public:
  static void Play(Chessman& chess) {
    taker_.SetMemento(chess.Save());
    index_++;
    std::cout << "Chess: " << chess.label() << ", x = " << chess.x()
              << ", y = " << chess.y() << std::endl;
  }

  static void Undo(Chessman& chess, int i) {
    std::cout << " ------ Undo -----" << std::endl;
    index_--;
    chess.Restore(taker_.GetMemento(i - 1));
    std::cout << "Chess: " << chess.label() << ", x = " << chess.x()
              << ", y = " << chess.y() << std::endl;
  }

  static void Redo(Chessman& chess, int i) {
    std::cout << " ------ Redo -----" << std::endl;
    index_++;
    chess.Restore(taker_.GetMemento(i + 1));
    std::cout << "Chess: " << chess.label() << ", x = " << chess.x()
              << ", y = " << chess.y() << std::endl;
  }

  static int index() { return index_; }

 private:
  static int index_;
  static CareTaker taker_;
};

int ChessPlay::index_ = -1;
CareTaker ChessPlay::taker_;

#endif  // BEHAVIORAL_MEMENTO_CHESSMAN_CHESSMAN_H_