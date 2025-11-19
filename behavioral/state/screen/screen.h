// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_STATE_SCREEN_SCREEN_H_
#define BEHAVIORAL_STATE_SCREEN_SCREEN_H_

#include <cassert>
#include <iostream>
#include <memory>

class State {
 public:
  virtual void Display() {}
};

class NormalState : public State {
 public:
  void Display() override { std::cout << "Normal Size..." << std::endl; }
};

class LargerState : public State {
 public:
  void Display() override { std::cout << "2X Size..." << std::endl; }
};

class LargestState : public State {
 public:
  void Display() override { std::cout << "4X Size..." << std::endl; }
};

class Screen {
 public:
  Screen()
      : normal_state_(std::make_unique<NormalState>()),
        larger_state_(std::make_unique<LargerState>()),
        largest_state_(std::make_unique<LargestState>()),
        curr_state_(normal_state_.get()) {
    curr_state_->Display();
  }

  void OnClick() {
    if (curr_state_ == normal_state_.get()) {
      SetState(larger_state_.get());
    } else if (curr_state_ == larger_state_.get()) {
      SetState(largest_state_.get());
    } else if (curr_state_ == largest_state_.get()) {
      SetState(normal_state_.get());
    } else {
      assert(false);
    }
    curr_state_->Display();
  }

 private:
  void SetState(State* state) { curr_state_ = state; }

  std::unique_ptr<NormalState> normal_state_;
  std::unique_ptr<LargerState> larger_state_;
  std::unique_ptr<LargestState> largest_state_;
  State* curr_state_;
};

#endif  // BEHAVIORAL_STATE_SCREEN_SCREEN_H_