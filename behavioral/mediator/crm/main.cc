// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <memory>

#include "component.h"
#include "mediator.h"

int main() {
  auto add_btn = std::make_shared<Button>();
  auto list = std::make_shared<List>();
  auto combo_box = std::make_shared<ComboBox>();
  auto text_box = std::make_shared<TextBox>();

  auto mediator = std::make_shared<CMediator>();
  mediator->set_add_btn(add_btn.get());
  mediator->set_list(list.get());
  mediator->set_combo_box(combo_box.get());
  mediator->set_text_box(text_box.get());

  add_btn->set_mediator(mediator);
  list->set_mediator(mediator);
  combo_box->set_mediator(mediator);
  text_box->set_mediator(mediator);

  add_btn->Changed();

  std::cout << "-------------------------" << std::endl;

  list->Changed();
  return 0;
}