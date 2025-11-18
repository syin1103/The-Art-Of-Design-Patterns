// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "stock.h"

int main() {
  ConcreteStock stock("ABCD", 100.0);

  auto investor1 = std::make_shared<ConcreteInvestor>("Tom");
  auto investor2 = std::make_shared<ConcreteInvestor>("Jack");
  auto investor3 = std::make_shared<ConcreteInvestor>("Lucy");

  stock.Attach(investor1);
  stock.Attach(investor2);
  stock.Attach(investor3);

  stock.set_price(200.0);

  return 0;
}