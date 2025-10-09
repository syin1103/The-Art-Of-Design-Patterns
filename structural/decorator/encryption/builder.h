// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_DECORATOR_ENCRYPTION_BUILDER_H_
#define STRUCTURAL_DECORATOR_ENCRYPTION_BUILDER_H_

#include <memory>

#include "decorator.h"
#include "encryption.h"

class EncryptionBuilder {
 public:
  EncryptionBuilder() : encryption_(std::make_unique<ShiftEncryption>()) {}

  EncryptionBuilder& WithReverse() {
    encryption_ = std::make_unique<ReverseDecorator>(std::move(encryption_));
    return *this;
  }

  EncryptionBuilder& WithMudulo() {
    encryption_ = std::make_unique<MuduloDecorator>(std::move(encryption_));
    return *this;
  }

  std::unique_ptr<Encryption> Build() { return std::move(encryption_); }

 private:
  std::unique_ptr<Encryption> encryption_;
};

#endif  // STRUCTURAL_DECORATOR_ENCRYPTION_BUILDER_H_