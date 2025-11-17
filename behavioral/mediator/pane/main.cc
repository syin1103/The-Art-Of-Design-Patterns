// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <memory>

#include "mediator.h"
#include "pane.h"

int main() {
  auto text_pane = std::make_shared<TextPane>();
  auto list_pane = std::make_shared<ListPane>();
  auto graphic_pane = std::make_shared<GraphicPane>();

  auto mediator = std::make_shared<PaneMediator>();
  mediator->set_text(text_pane.get());
  mediator->set_list(list_pane.get());
  mediator->set_graphic(graphic_pane.get());

  text_pane->set_mediator(mediator);
  list_pane->set_mediator(mediator);
  graphic_pane->set_mediator(mediator);

  text_pane->Changed();
  std::cout << "---------" << std::endl;

  list_pane->Changed();
  std::cout << "---------" << std::endl;

  graphic_pane->Changed();

  return 0;
}