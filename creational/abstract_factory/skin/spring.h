// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_ABSTRACT_FACTORY_SKIN_SPRING_H_
#define CREATIONAL_ABSTRACT_FACTORY_SKIN_SPRING_H_

#include <iostream>

#include "component.h"

class SpringButton : public Button {
 public:
  void Display() override {
    std::cout << "Display SpringButton..." << std::endl;
  }
};

class SpringTextField : public TextField {
 public:
  void Display() override {
    std::cout << "Display SpringTextField..." << std::endl;
  }
};

class SpringComboBox : public ComboBox {
 public:
  void Display() override {
    std::cout << "Display SpringComboBox..." << std::endl;
  }
};

#endif  // CREATIONAL_ABSTRACT_FACTORY_SKIN_SPRING_H_