// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <memory>
#include <string>

#include "approver.h"

int main() {
  PurchaseRequese request(400000, 1527, "house");

  auto congress = std::make_shared<Congress>("Congress");

  auto president = std::make_shared<President>("Tom");
  president->set_successor(congress);

  auto vice_president = std::make_shared<VicePresident>("Jerry");
  vice_president->set_successor(president);

  auto director = std::make_shared<Director>("Bob");
  director->set_successor(vice_president);

  director->ProcessRequest(request);

  return 0;
}