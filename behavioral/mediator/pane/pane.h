// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_MEDIATOR_PANE_PANE_H_
#define BEHAVIORAL_MEDIATOR_PANE_PANE_H_

#include <iostream>
#include <memory>

#include "mediator.h"

class Pane {
 public:
  void set_mediator(std::shared_ptr<Mediator> mediator) {
    mediator_ = mediator;
  }

  void Changed() { mediator_->Changed(this); }

 protected:
  std::shared_ptr<Mediator> mediator_ = nullptr;
};

class TextPane : public Pane {
 public:
  void HandleReq() { std::cout << "TextPane handle..." << std::endl; }
};

class ListPane : public Pane {
 public:
  void HandleReq() { std::cout << "ListPane handle..." << std::endl; }
};

class GraphicPane : public Pane {
 public:
  void HandleReq() { std::cout << "GraphicPane handle..." << std::endl; }
};

#endif  // BEHAVIORAL_MEDIATOR_PANE_PANE_H_