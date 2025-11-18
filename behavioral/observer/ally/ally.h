// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_OBSERVER_ALLY_ALLY_H_
#define BEHAVIORAL_OBSERVER_ALLY_ALLY_H_

#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>

class AllyControlCenter;

class IObserver {
 public:
  IObserver(const std::string& name) : name_(name) {}
  virtual ~IObserver() {}

  std::string name() const { return name_; }
  void set_name(const std::string& name) { name_ = name; }

  void Help() const { std::cout << "Help: " << name_ << std::endl; }
  virtual void BeAttacked(const AllyControlCenter& control) = 0;

 protected:
  std::string name_;
};

class AllyControlCenter {
 public:
  void Attach(std::shared_ptr<IObserver> observer) {
    assert(observer != nullptr);
    observers_.insert(observer);
  }

  void Remove(std::shared_ptr<IObserver> observer) {
    observers_.erase(observer);
  }

  void NotifyAll(const std::string& name) const {
    for (const auto& observer : observers_) {
      if (observer->name() != name) {
        observer->Help();
      }
    }
  }

 private:
  std::unordered_set<std::shared_ptr<IObserver>> observers_;
};

class Player : public IObserver {
 public:
  explicit Player(const std::string& name) : IObserver(name) {}
  virtual ~Player() {}

  void BeAttacked(const AllyControlCenter& control) override {
    control.NotifyAll(name());
  }
};

#endif  // BEHAVIORAL_OBSERVER_ALLY_ALLY_H_