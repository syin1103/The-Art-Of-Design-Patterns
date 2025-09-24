// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <iostream>

#include "encryptor_adaptor.h"

int main() {
  EncryptorA encryptor_a;
  EncryptorB encryptor_b;

  std::cout << encryptor_a.Encrypt("HelloWorld") << std::endl;
  std::cout << encryptor_b.Encrypt("HelloWorld") << std::endl;

  return 0;
}