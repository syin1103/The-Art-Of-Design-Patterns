// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "skin_factory.h"

#include "component.h"

int main() {
  SpringFactory spring_factory;
  auto button = spring_factory.CreateButton();
  auto textfield = spring_factory.CreateTextField();
  auto combobox = spring_factory.CreateComboBox();

  button->Display();
  textfield->Display();
  combobox->Display();

  return 0;
}