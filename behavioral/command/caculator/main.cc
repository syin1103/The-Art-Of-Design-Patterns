// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "caculator.h"
#include "caculator_form.h"
#include "command.h"

int main() {
  Caculator calc;
  CaculatorForm calc_form;

  auto add10 = std::make_unique<AddCommand>(calc, 10);
  auto add20 = std::make_unique<AddCommand>(calc, 20);
  auto subtract5 = std::make_unique<SubtractCommand>(calc, 5);
  auto subtract10 = std::make_unique<SubtractCommand>(calc, 10);

  std::cout << calc_form.Compute(std::move(add10)) << std::endl;
  std::cout << calc_form.Compute(std::move(add20)) << std::endl;
  std::cout << calc_form.Compute(std::move(subtract5)) << std::endl;
  std::cout << calc_form.Compute(std::move(subtract10)) << std::endl;

  calc_form.Undo();
  calc_form.Undo();
  calc_form.Undo();
  calc_form.Redo();
  calc_form.Redo();
  calc_form.Undo();
  calc_form.Undo();
  calc_form.Undo();
  calc_form.Undo();

  return 0;
}