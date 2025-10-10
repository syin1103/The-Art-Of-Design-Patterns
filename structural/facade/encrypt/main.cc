// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <string>

#include "facade.h"

int main() {
  EncryptFacade encryptor;
  encryptor.Encrypt("src.txt", "des.txt");
  return 0;
}