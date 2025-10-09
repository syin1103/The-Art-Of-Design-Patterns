// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_DECORATOR_ENCRYPTION_DECORATOR_H_
#define STRUCTURAL_DECORATOR_ENCRYPTION_DECORATOR_H_

#include <memory>

#include "encryption.h"

class Decorator : public Encryption {
 public:
  Decorator(std::unique_ptr<Encryption> encryption)
      : encryption_(std::move(encryption)) {}

  virtual std::string Encrypt(const std::string& s) {
    return encryption_->Encrypt(s);
  }

 protected:
  std::unique_ptr<Encryption> encryption_;
};

class ReverseDecorator : public Decorator {
 public:
  ReverseDecorator(std::unique_ptr<Encryption> encryption)
      : Decorator(std::move(encryption)) {}

  std::string Encrypt(const std::string& s) override {
    auto ens = encryption_->Encrypt(s);
    return "Reverse: " + ens;
  }
};

class MuduloDecorator : public Decorator {
 public:
  MuduloDecorator(std::unique_ptr<Encryption> encryption)
      : Decorator(std::move(encryption)) {}

  std::string Encrypt(const std::string& s) override {
    auto ens = encryption_->Encrypt(s);
    return "Mudulo: " + ens;
  }
};

#endif  // STRUCTURAL_DECORATOR_ENCRYPTION_DECORATOR_H_