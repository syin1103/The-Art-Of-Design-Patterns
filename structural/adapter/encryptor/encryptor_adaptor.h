// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_ADAPTER_ENCRYPTOR_ADAPTER_H_
#define STRUCTURAL_ADAPTER_ENCRYPTOR_ADAPTER_H_

#include <memory>
#include <string>

#include "encryptor_algo.h"

class Encryptor {
 public:
  Encryptor() {}
  virtual ~Encryptor() {}

  virtual std::string Encrypt(const std::string& data) = 0;
  virtual std::string Decrypt(const std::string& data) = 0;
};

class EncryptorA : public Encryptor {
 public:
  EncryptorA() : algo_(std::make_unique<EncryptorAlgoA>()) {}
  virtual ~EncryptorA() {}

  std::string Encrypt(const std::string& data) override {
    return algo_->EncryptData(data);
  }

  std::string Decrypt(const std::string& data) override {
    return algo_->DecryptData(data);
  }

 private:
  std::unique_ptr<EncryptorAlgoA> algo_;
};

class EncryptorB : public Encryptor {
 public:
  EncryptorB() : algo_(std::make_unique<EncryptorAlgoB>()) {}
  virtual ~EncryptorB() {}

  std::string Encrypt(const std::string& data) override {
    return algo_->SecureEncrypt(data);
  }

  std::string Decrypt(const std::string& data) override {
    return algo_->SecureDecrypt(data);
  }

 private:
  std::unique_ptr<EncryptorAlgoB> algo_;
};

#endif  // STRUCTURAL_ADAPTER_ENCRYPTOR_ADAPTER_H_