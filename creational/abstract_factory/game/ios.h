// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_ABSTRACT_FACTORY_GAME_IOS_H_
#define CREATIONAL_ABSTRACT_FACTORY_GAME_IOS_H_

#include <iostream>

#include "controller.h"

class IOSInterfaceController : public InterfaceController {
 public:
  void Render() override { std::cout << "IOS render..." << std::endl; }
};

class IOSOperationController : public OperationController {
 public:
  void Process() override { std::cout << "IOS process..." << std::endl; }
};

#endif  // CREATIONAL_ABSTRACT_FACTORY_GAME_IOS_H_