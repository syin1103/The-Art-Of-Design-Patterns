// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef SINGLETON_CREATIONAL_SIMPLE_FACTORY_SHAPE_SHAPE_FACTORY_H_
#define SINGLETON_CREATIONAL_SIMPLE_FACTORY_SHAPE_SHAPE_FACTORY_H_

#include <memory>
#include <string>

#include "exception.h"
#include "shape.h"

class ShapeFactory {
 public:
  static std::unique_ptr<Shape> Create(const std::string& type) {
    if (type == "Circle") {
      return std::make_unique<Circle>();
    } else if (type == "Square") {
      return std::make_unique<Square>();
    } else if (type == "Triangle") {
      return std::make_unique<Triangle>();
    } else {
      throw UnSupportedShapeException(type);
    }
  }
};

#endif  // SINGLETON_CREATIONAL_SIMPLE_FACTORY_SHAPE_SHAPE_FACTORY_H_