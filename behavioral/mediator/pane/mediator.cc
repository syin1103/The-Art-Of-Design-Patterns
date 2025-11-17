// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "mediator.h"

#include "pane.h"

void PaneMediator::Changed(Pane* pane) {
  if (pane == text_) {
    text_->HandleReq();
    list_->HandleReq();
  } else if (pane == list_) {
    list_->HandleReq();
  } else if (pane == graphic_) {
    graphic_->HandleReq();
    text_->HandleReq();
    list_->HandleReq();
  }
}