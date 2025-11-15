// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <iostream>
#include <string>
#include <vector>

#include "object_list.h"

int main() {
  ProductList products({"House", "Car", "Book", "PS5"});
  auto iterator = products.CreateIterator();

  std::cout << "Forward..." << std::endl;
  while (!iterator->IsLast()) {
    std::cout << iterator->GetNextItem() << ", ";
    iterator->Next();
  }

  std::cout << "\nReverse..." << std::endl;
  while (!iterator->IsFirst()) {
    std::cout << iterator->GetPrevItem() << ", ";
    iterator->Previous();
  }
  std::cout << std::endl;

  return 0;
}