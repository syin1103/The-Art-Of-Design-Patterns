// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <iostream>
#include <string>

#include "searcher.h"

int main() {
  SearcherProxy proxy;
  std::string res = proxy.DoSearch("1234", "key");
  std::cout << "Search: " << res << std::endl;
  return 0;
}