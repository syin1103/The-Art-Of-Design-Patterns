// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_STATE_PLAYER_PLAYER_H_
#define BEHAVIORAL_STATE_PLAYER_PLAYER_H_

#include <iostream>
#include <memory>

class State {
 public:
  virtual void Play() { std::cout << "Unsupport Play" << std::endl; }

  virtual void DoubleScore() {
    std::cout << "Unsupport DoubleScore" << std::endl;
  }

  virtual void ChangeCards() {
    std::cout << "Unsupport ChangeCards" << std::endl;
  }

  virtual void PeekCards() { std::cout << "Unsupport PeekCards" << std::endl; }
};

class PrimaryState : public State {
 public:
  void Play() override { std::cout << "Play Game..." << std::endl; }
};

class SecondaryState : public State {
 public:
  void Play() override { std::cout << "Play Game..." << std::endl; }
  void DoubleScore() override { std::cout << "Double Score..." << std::endl; }
};

class ProfessionalState : public State {
 public:
  void Play() override { std::cout << "Play Game..." << std::endl; }
  void DoubleScore() override { std::cout << "Double Score..." << std::endl; }
  void ChangeCards() override { std::cout << "ChangeCards..." << std::endl; }
};

class FinalState : public State {
 public:
  void Play() override { std::cout << "Play Game..." << std::endl; }
  void DoubleScore() override { std::cout << "Double Score..." << std::endl; }
  void ChangeCards() override { std::cout << "ChangeCards..." << std::endl; }
  void PeekCards() { std::cout << "PeekCards..." << std::endl; }
};

class Player {
 public:
  Player(int score = 0) : score_(score) { UpdateStateOrNot(score); }

  void Win(int score) {
    score_ += score;
    UpdateStateOrNot(score_);
  }

  void Lose(int score) {
    score_ -= score;
    UpdateStateOrNot(score_);
  }

  void Play() { curr_state_->Play(); }
  void DoubleScore() { curr_state_->DoubleScore(); }
  void ChangeCards() { curr_state_->ChangeCards(); }
  void PeekCards() { curr_state_->PeekCards(); }

 private:
  void UpdateStateOrNot(int score) {
    if (score_ < 1000) {
      SetState(std::make_unique<PrimaryState>());
    } else if (score_ < 2000) {
      SetState(std::make_unique<SecondaryState>());
    } else if (score_ < 3000) {
      SetState(std::make_unique<ProfessionalState>());
    } else {
      SetState(std::make_unique<FinalState>());
    }
  }

  void SetState(std::unique_ptr<State> state) {
    curr_state_ = std::move(state);
  }

  int score_;
  std::unique_ptr<State> curr_state_;
};

#endif  // BEHAVIORAL_STATE_PLAYER_PLAYER_H_