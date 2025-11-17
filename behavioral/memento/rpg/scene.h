// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_MEMENTO_RPG_SCENE_H_
#define BEHAVIORAL_MEMENTO_RPG_SCENE_H_

#include <iostream>
#include <memory>
#include <string>

class GameMemento {
 public:
  GameMemento(const std::string& state) : state_(state) {}
  std::string state() const { return state_; }

 private:
  std::string state_;
};

class GameScene {
 public:
  GameScene(const std::string& state) : state_(state) {}

  void Play() { std::cout << "Play Scene: " << state_ << std::endl; }

  void set_state(const std::string& state) { state_ = state; }

  std::unique_ptr<GameMemento> Save() const {
    return std::make_unique<GameMemento>(state_);
  }

  void Load(const GameMemento* memento) {
    state_ = memento->state();
    std::cout << "Load Scene: " << state_ << std::endl;
  }

 private:
  std::string state_;
};

class SceneManager {
 public:
  void QuickSave(const GameScene& scene) {
    memento_ = scene.Save();
    std::cout << "Quick Save Scene: " << memento_->state() << std::endl;
  }

  void QuickLoad(GameScene& scene) {
    if (memento_ == nullptr) {
      std::cout << "Has no history scene" << std::endl;
    } else {
      scene.Load(memento_.get());
    }
    std::cout << "Quick Load Scene: " << memento_->state() << std::endl;
  }

 private:
  std::unique_ptr<GameMemento> memento_ = nullptr;
};

#endif  // BEHAVIORAL_MEMENTO_RPG_SCENE_H_