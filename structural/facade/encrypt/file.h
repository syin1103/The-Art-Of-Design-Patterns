// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_FACADE_ENCRYPT_FILE_H_
#define STRUCTURAL_FACADE_ENCRYPT_FILE_H_

#include <iostream>
#include <string>

class FileReader {
 public:
  std::string Read(const std::string& filename) {
    std::cout << "Read date from " << filename << std::endl;
    return "";
  }
};

class CipherMachine {
 public:
  std::string Encrypt(const std::string& text) {
    std::cout << "Encrypt data..." << std::endl;
    return "Encrypt: " + text;
  }
};

class FileWriter {
 public:
  void Write(const std::string& es, const std::string& filename) {
    std::cout << "Write data to " << filename << std::endl;
  }
};

#endif  // STRUCTURAL_FACADE_ENCRYPT_FILE_H_