// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_MEDIATOR_CRM_MEDIATOR_H_
#define BEHAVIORAL_MEDIATOR_CRM_MEDIATOR_H_

#include <memory>

class Component;
class Button;
class List;
class TextBox;
class ComboBox;

class Mediator {
 public:
  virtual ~Mediator() {}
  virtual void ComponentChanged(Component* component) = 0;
};

class CMediator : public Mediator {
 public:
  virtual ~CMediator() {}
  void ComponentChanged(Component* component) override;

  void set_add_btn(Button* btn) { add_btn_ = btn; }
  void set_list(List* list) { list_ = list; }
  void set_text_box(TextBox* box) { text_box_ = box; }
  void set_combo_box(ComboBox* box) { combo_box_ = box; }

 private:
  Button* add_btn_ = nullptr;
  List* list_ = nullptr;
  TextBox* text_box_ = nullptr;
  ComboBox* combo_box_ = nullptr;
};

#endif  // BEHAVIORAL_MEDIATOR_CRM_MEDIATOR_H_