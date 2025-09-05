// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "shape_factory.h"

#include <iostream>

#include "shape.h"

int main() {
  auto circle = ShapeFactory::Create("Circle");
  circle->Draw();
  circle->Erase();

  auto square = ShapeFactory::Create("Square");
  square->Draw();
  square->Erase();

  auto triangle = ShapeFactory::Create("Triangle");
  triangle->Draw();
  triangle->Erase();

  return 0;
}