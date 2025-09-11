// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_BUILDER_ACTOR_ACTOR_CONTROLLER_H_
#define CREATIONAL_BUILDER_ACTOR_ACTOR_CONTROLLER_H_

#include <memory>

#include "actor.h"
#include "actor_builder.h"

class ActorController {
 public:
  ActorController() = default;
  ~ActorController() = default;

  ActorController(const ActorController&) = delete;
  ActorController& operator=(const ActorController&) = delete;

  Actor Construct() {
    if (builder_ == nullptr) {
      return {};
    }

    builder_->BuildType();
    builder_->BuildSex();
    builder_->BuildFace();
    builder_->BuildCustome();

    if (!builder_->IsBaldHead()) {
      builder_->BuildHairstyle();
    }

    return builder_->CreateActor();
  }

  void set_builder(std::unique_ptr<ActorBuilder> builder) {
    builder_ = std::move(builder);
  }

 private:
  std::unique_ptr<ActorBuilder> builder_ = nullptr;
};

#endif  // CREATIONAL_BUILDER_ACTOR_ACTOR_CONTROLLER_H_