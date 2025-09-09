// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_ABSTRACT_FACTORY_SKIN_SUMMER_H_
#define CREATIONAL_ABSTRACT_FACTORY_SKIN_SUMMER_H_

#include <iostream>

#include "component.h"

class SummerButton : public Button {
 public:
  void Display() override {
    std::cout << "Display SummerButton..." << std::endl;
  }
};

class SummerTextField : public TextField {
 public:
  void Display() override {
    std::cout << "Display SummerTextField..." << std::endl;
  }
};

class SummerComboBox : public ComboBox {
 public:
  void Display() override {
    std::cout << "Display SummerComboBox..." << std::endl;
  }
};

#endif  // CREATIONAL_ABSTRACT_FACTORY_SKIN_SUMMER_H_