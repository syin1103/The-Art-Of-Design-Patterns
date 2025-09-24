// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_ADAPTER_ENCRYPTOR_ALGO_H_
#define STRUCTURAL_ADAPTER_ENCRYPTOR_ALGO_H_

#include <string>

class EncryptorAlgoA {
 public:
  std::string EncryptData(const std::string& data) { return "aloga_" + data; }
  std::string DecryptData(const std::string& data) { return ""; }
};

class EncryptorAlgoB {
 public:
  std::string SecureEncrypt(const std::string& data) { return "alogb_" + data; }
  std::string SecureDecrypt(const std::string& data) { return ""; }
};

#endif  // STRUCTURAL_ADAPTER_ENCRYPTOR_ALGO_H_