// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "mediator.h"

#include <iostream>

#include "component.h"

void CMediator::ComponentChanged(Component* component) {
  if (component == add_btn_) {
    std::cout << " --- Click Add Button ---" << std::endl;
    list_->Update();
    combo_box_->Update();
    text_box_->Update();
  } else if (component == list_) {
    std::cout << " --- Select Customer From List ---" << std::endl;
    combo_box_->Select();
    text_box_->SetText();
  } else if (component == combo_box_) {
    std::cout << "Select Customer From ComboBox ---" << std::endl;
  }
}