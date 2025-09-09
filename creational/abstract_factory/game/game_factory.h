// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_ABSTRACT_FACTORY_GAME_GAME_FACTORY_H_
#define CREATIONAL_ABSTRACT_FACTORY_GAME_GAME_FACTORY_H_

#include <memory>

#include "android.h"
#include "ios.h"

class GameFactory {
 public:
  virtual std::unique_ptr<InterfaceController> CreateInterfaceController() = 0;
  virtual std::unique_ptr<OperationController> CreateOperatiionController() = 0;
};

class IOSFactory : public GameFactory {
 public:
  std::unique_ptr<InterfaceController> CreateInterfaceController() override {
    return std::make_unique<IOSInterfaceController>();
  }

  std::unique_ptr<OperationController> CreateOperatiionController() override {
    return std::make_unique<IOSOperationController>();
  }
};

class AndroidFactory : public GameFactory {
 public:
  std::unique_ptr<InterfaceController> CreateInterfaceController() override {
    return std::make_unique<AndroidInterfaceController>();
  }

  std::unique_ptr<OperationController> CreateOperatiionController() override {
    return std::make_unique<AndroidOperationController>();
  }
};

#endif  // CREATIONAL_ABSTRACT_FACTORY_GAME_GAME_FACTORY_H_