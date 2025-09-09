// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_ABSTRACT_FACTORY_SKIN_COMPONENT_H_
#define CREATIONAL_ABSTRACT_FACTORY_SKIN_COMPONENT_H_

class Button {
 public:
  virtual void Display() = 0;
};

class TextField {
 public:
  virtual void Display() = 0;
};

class ComboBox {
 public:
  virtual void Display() = 0;
};

#endif  // CREATIONAL_ABSTRACT_FACTORY_SKIN_COMPONENT_H_