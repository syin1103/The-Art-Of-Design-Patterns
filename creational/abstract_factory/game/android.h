// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_ABSTRACT_FACTORY_GAME_ANDROID_H_
#define CREATIONAL_ABSTRACT_FACTORY_GAME_ANDROID_H_

#include <iostream>

#include "controller.h"

class AndroidInterfaceController : public InterfaceController {
 public:
  void Render() override { std::cout << "Android render..." << std::endl; }
};

class AndroidOperationController : public OperationController {
 public:
  void Process() override { std::cout << "Android process..." << std::endl; }
};

#endif  // CREATIONAL_ABSTRACT_FACTORY_GAME_ANDROID_H_