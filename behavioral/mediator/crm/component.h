// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_MEDIATOR_CRM_COMPONENT_H_
#define BEHAVIORAL_MEDIATOR_CRM_COMPONENT_H_

#include <iostream>
#include <memory>
#include <string>

#include "mediator.h"

class Component {
 public:
  virtual ~Component() {}

  void set_mediator(std::shared_ptr<Mediator> mediator) {
    mediator_ = mediator;
  }

  void Changed() { mediator_->ComponentChanged(this); }

  virtual void Update() = 0;

 protected:
  std::shared_ptr<Mediator> mediator_ = nullptr;
};

class Button : public Component {
 public:
  void Update() override { /*Do Nothing*/ }
};

class List : public Component {
 public:
  void Update() override {
    std::cout << "Add an item to the list: ZhangWuji" << std::endl;
  }

  void Select() { std::cout << "Select item in list: XiaoLongnv" << std::endl; }
};

class ComboBox : public Component {
 public:
  void Update() override {
    std::cout << "Add an item to ComboBox: ZhangWuji" << std::endl;
  }

  void Select() {
    std::cout << "Select item in ComboBox: XiaoLongnv" << std::endl;
  }
};

class TextBox : public Component {
 public:
  void Update() override {
    std::cout << "The text is cleared after customer information is "
                 "successfully added."
              << std::endl;
  }

  void SetText() { std::cout << "TextBox display: XiaoLongnv" << std::endl; }
};

#endif  // BEHAVIORAL_MEDIATOR_CRM_COMPONENT_H_