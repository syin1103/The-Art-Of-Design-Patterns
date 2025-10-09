// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_DECORATOR_COMPONENT_COMPONENT_H_
#define STRUCTURAL_DECORATOR_COMPONENT_COMPONENT_H_

#include <iostream>

class Component {
 public:
  virtual void Display() = 0;
};

class Windows : public Component {
 public:
  void Display() override { std::cout << "Show windows..." << std::endl; }
};

class TextBox : public Component {
 public:
  void Display() override { std::cout << "Show textbox..." << std::endl; }
};

class ListBox : public Component {
 public:
  void Display() override { std::cout << "Show listbox..." << std::endl; }
};

#endif  // STRUCTURAL_DECORATOR_COMPONENT_COMPONENT_H_