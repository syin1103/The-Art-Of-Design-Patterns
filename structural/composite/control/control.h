// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_COMPOSITE_CONTROL_H_
#define STRUCTURAL_COMPOSITE_CONTROL_H_

#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class Control {
 public:
  Control(const std::string& name) : name_(name) {}

  virtual void Add(std::shared_ptr<Control> control) {
    throw std::runtime_error("Unsupport add operation.");
  }

  virtual void Remove(std::shared_ptr<Control> control) {
    throw std::runtime_error("Unsupport remove operation.");
  }

  virtual std::shared_ptr<Control> GetChild(int index) {
    throw std::runtime_error("Unsupport GetChild operation.");
  }

  virtual void Draw() = 0;

  std::string name() { return name_; }

 private:
  std::string name_;
};

class Button : public Control {
 public:
  Button(const std::string& name) : Control(name) {}
  void Draw() override { std::cout << "Draw button : " << name() << std::endl; }
};

class TextBox : public Control {
 public:
  TextBox(const std::string& name) : Control(name) {}
  void Draw() override {
    std::cout << "Draw textbox : " << name() << std::endl;
  }
};

class ContainerControl : public Control {
 public:
  ContainerControl(const std::string& name) : Control(name) {}

  void Add(std::shared_ptr<Control> control) override {
    elements_.emplace_back(control);
  }

  void Remove(std::shared_ptr<Control> control) override {
    auto it = std::find(elements_.begin(), elements_.end(), control);
    if (it != elements_.end()) {
      elements_.erase(it);
    }
  }

  std::shared_ptr<Control> GetChild(int index) override {
    if (index < elements_.size()) {
      return elements_[index];
    }
    return nullptr;
  }

  void Draw() override {
    for (const auto& elem : elements_) {
      elem->Draw();
    }
  }

 private:
  std::vector<std::shared_ptr<Control>> elements_;
};

class Window : public ContainerControl {
 public:
  Window(const std::string& name) : ContainerControl("[Window]: " + name) {}
};

class Panel : public ContainerControl {
 public:
  Panel(const std::string& name) : ContainerControl("[Panel]: " + name) {}
};

#endif  // STRUCTURAL_COMPOSITE_CONTROL_H_