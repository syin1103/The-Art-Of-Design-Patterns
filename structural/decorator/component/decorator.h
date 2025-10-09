// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_DECORATOR_COMPONENT_DECORATOR_H_
#define STRUCTURAL_DECORATOR_COMPONENT_DECORATOR_H_

#include <iostream>
#include <memory>

#include "component.h"

class ComponentDecorator : public Component {
 public:
  ComponentDecorator(std::unique_ptr<Component> component)
      : component_(std::move(component)) {}

  virtual void Display() { component_->Display(); }

 private:
  std::unique_ptr<Component> component_;
};

class ScrollBarDecorator : public ComponentDecorator {
 public:
  ScrollBarDecorator(std::unique_ptr<Component> component)
      : ComponentDecorator(std::move(component)) {}

  void Display() override {
    SetScrollBar();
    ComponentDecorator::Display();
  }

 private:
  void SetScrollBar() { std::cout << "Set scrollBar..." << std::endl; }
};

class BlackBorderDecorator : public ComponentDecorator {
 public:
  BlackBorderDecorator(std::unique_ptr<Component> component)
      : ComponentDecorator(std::move(component)) {}

  void Display() override {
    SetBlackBorder();
    ComponentDecorator::Display();
  }

 private:
  void SetBlackBorder() { std::cout << "Set blackborder..." << std::endl; }
};

#endif  // STRUCTURAL_DECORATOR_COMPONENT_DECORATOR_H_