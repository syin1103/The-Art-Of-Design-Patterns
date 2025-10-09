// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <memory>

#include "component.h"
#include "decorator.h"

int main() {
  std::unique_ptr<Component> windows = std::make_unique<Windows>();
  std::unique_ptr<Component> sbar =
      std::make_unique<ScrollBarDecorator>(std::move(windows));
  sbar->Display();

  return 0;
}