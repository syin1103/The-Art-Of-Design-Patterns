// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "actor.h"

#include <memory>

#include "actor_controller.h"

int main() {
  ActorController controller;

  controller.set_builder(std::make_unique<HeroBuilder>());
  Actor actor1 = controller.Construct();
  actor1.Display();

  controller.set_builder(std::make_unique<AngelBuilder>());
  Actor actor2 = controller.Construct();
  actor2.Display();

  controller.set_builder(std::make_unique<DevilBuilder>());
  Actor actor3 = controller.Construct();
  actor3.Display();
  return 0;
}