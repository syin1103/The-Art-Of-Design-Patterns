// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_STRATEGY_AIRPLANE_AIRPLANE_H_
#define BEHAVIORAL_STRATEGY_AIRPLANE_AIRPLANE_H_

#include <iostream>
#include <memory>
#include <string>

class TakeOffBehavior {
 public:
  virtual ~TakeOffBehavior() {}
  virtual void TakeOff() = 0;
};

class VerticalTakeOff : public TakeOffBehavior {
 public:
  virtual ~VerticalTakeOff() {}
  void TakeOff() override { std::cout << "Vertical Take Off..." << std::endl; }
};

class LongDistanceTakeOff : public TakeOffBehavior {
  void TakeOff() override {
    std::cout << "Long Distance Take Off..." << std::endl;
  }
};

class FlyBehavior {
 public:
  virtual ~FlyBehavior() {}
  virtual void Fly() = 0;
};

class SubSonicFly : public FlyBehavior {
 public:
  virtual ~SubSonicFly() {}
  void Fly() override { std::cout << "SubSonic Fly..." << std::endl; }
};

class SuperSonicFly : public FlyBehavior {
 public:
  virtual ~SuperSonicFly() {}
  void Fly() override { std::cout << "Super Fly..." << std::endl; }
};

class AirCraft {
 public:
  AirCraft(std::unique_ptr<TakeOffBehavior> take_off,
           std::unique_ptr<FlyBehavior> fly)
      : take_off_(std::move(take_off)), fly_(std::move(fly)) {}

  void TakeOff() {
    if (take_off_ != nullptr) {
      take_off_->TakeOff();
    }
  }

  void Fly() {
    if (fly_ != nullptr) {
      fly_->Fly();
    }
  }

 private:
  std::unique_ptr<TakeOffBehavior> take_off_;
  std::unique_ptr<FlyBehavior> fly_;
};

#endif  // BEHAVIORAL_STRATEGY_AIRPLANE_AIRPLANE_H_