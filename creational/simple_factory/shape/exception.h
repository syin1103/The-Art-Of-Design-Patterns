// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef SINGLETON_CREATIONAL_SIMPLE_FACTORY_SHAPE_EXCEPTION_H_
#define SINGLETON_CREATIONAL_SIMPLE_FACTORY_SHAPE_EXCEPTION_H_

#include <stdexcept>

class UnSupportedShapeException : public std::runtime_error {
 public:
  explicit UnSupportedShapeException(const std::string& shape)
      : std::runtime_error("Unsupport shape: " + shape) {}
};

#endif  // SINGLETON_CREATIONAL_SIMPLE_FACTORY_SHAPE_EXCEPTION_H_