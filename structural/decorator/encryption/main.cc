// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "builder.h"
#include "encryption.h"

int main() {
  auto encryption = EncryptionBuilder().WithReverse().WithMudulo().Build();
  auto res = encryption->Encrypt("Hello Wolrd");
  std::cout << res << std::endl;
  return 0;
}