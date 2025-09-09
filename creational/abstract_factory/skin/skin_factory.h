// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_ABSTRACT_FACTORY_SKIN_SKIN_FACTORY_H_
#define CREATIONAL_ABSTRACT_FACTORY_SKIN_SKIN_FACTORY_H_

#include <memory>

#include "spring.h"
#include "summer.h"

class SkinFactory {
 public:
  virtual std::unique_ptr<Button> CreateButton() = 0;
  virtual std::unique_ptr<TextField> CreateTextField() = 0;
  virtual std::unique_ptr<ComboBox> CreateComboBox() = 0;
};

class SpringFactory : public SkinFactory {
 public:
  std::unique_ptr<Button> CreateButton() override {
    return std::make_unique<SpringButton>();
  }

  std::unique_ptr<TextField> CreateTextField() override {
    return std::make_unique<SpringTextField>();
  }

  std::unique_ptr<ComboBox> CreateComboBox() override {
    return std::make_unique<SpringComboBox>();
  }
};

class SummerFactory : public SkinFactory {
  std::unique_ptr<Button> CreateButton() override {
    return std::make_unique<SummerButton>();
  }

  std::unique_ptr<TextField> CreateTextField() override {
    return std::make_unique<SummerTextField>();
  }

  std::unique_ptr<ComboBox> CreateComboBox() override {
    return std::make_unique<SummerComboBox>();
  }
};

#endif  // CREATIONAL_ABSTRACT_FACTORY_SKIN_SKIN_FACTORY_H_