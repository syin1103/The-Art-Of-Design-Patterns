// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_DECORATOR_ENCRYPTION_ENCRYPTION_H_
#define STRUCTURAL_DECORATOR_ENCRYPTION_ENCRYPTION_H_

#include <iostream>
#include <string>

class Encryption {
 public:
  virtual std::string Encrypt(const std::string& s) = 0;
};

class ShiftEncryption : public Encryption {
 public:
  std::string Encrypt(const std::string& s) override { return "Shift: " + s; }
};

#endif  // STRUCTURAL_DECORATOR_ENCRYPTION_ENCRYPTION_H_