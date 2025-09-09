// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "game_factory.h"

#include <iostream>
#include <memory>

#include "android.h"
#include "ios.h"

std::unique_ptr<GameFactory> CreateFactory(const std::string& type) {
  if (type == "android") {
    return std::make_unique<AndroidFactory>();
  } else if (type == "ios") {
    return std::make_unique<IOSFactory>();
  } else {
    return nullptr;
  }
}

int main() {
  auto factory1 = CreateFactory("android");
  auto icontroller1 = factory1->CreateInterfaceController();
  auto ocontroller1 = factory1->CreateOperatiionController();

  icontroller1->Render();
  ocontroller1->Process();

  auto factory2 = CreateFactory("ios");
  auto icontroller2 = factory2->CreateInterfaceController();
  auto ocontroller2 = factory2->CreateOperatiionController();

  icontroller2->Render();
  ocontroller2->Process();
  return 0;
}