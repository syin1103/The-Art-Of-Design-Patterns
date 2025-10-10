// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_FACADE_ENCRYPT_FACADE_H_
#define STRUCTURAL_FACADE_ENCRYPT_FACADE_H_

#include <memory>
#include <string>

#include "file.h"

class EncryptFacade {
 public:
  EncryptFacade()
      : reader_(std::make_unique<FileReader>()),
        cipher_(std::make_unique<CipherMachine>()),
        writer_(std::make_unique<FileWriter>()) {}

  void Encrypt(const std::string& src, const std::string& des) {
    std::string plain_text = reader_->Read(src);
    std::string es = cipher_->Encrypt(plain_text);
    writer_->Write(es, des);
  }

 private:
  std::unique_ptr<FileReader> reader_;
  std::unique_ptr<CipherMachine> cipher_;
  std::unique_ptr<FileWriter> writer_;
};

#endif  // STRUCTURAL_FACADE_ENCRYPT_FACADE_H_