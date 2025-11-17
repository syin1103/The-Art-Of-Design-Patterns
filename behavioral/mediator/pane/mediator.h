// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_MEDIATOR_PANE_MEDIATOR_H_
#define BEHAVIORAL_MEDIATOR_PANE_MEDIATOR_H_

#include "mediator.h"

class Pane;
class TextPane;
class ListPane;
class GraphicPane;

class Mediator {
 public:
  virtual ~Mediator() {}
  virtual void Changed(Pane* pane) = 0;
};

class PaneMediator : public Mediator {
 public:
  virtual ~PaneMediator() {}
  void Changed(Pane* pane) override;

  void set_text(TextPane* text) { text_ = text; }
  void set_list(ListPane* list) { list_ = list; }
  void set_graphic(GraphicPane* graphic) { graphic_ = graphic; }

 private:
  TextPane* text_ = nullptr;
  ListPane* list_ = nullptr;
  GraphicPane* graphic_ = nullptr;
};

#endif  // BEHAVIORAL_MEDIATOR_PANE_MEDIATOR_H_