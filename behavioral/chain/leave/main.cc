// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <memory>
#include <string>

#include "approver.h"

int main() {
  LeaveRequese request(20, "happy");

  auto general = std::make_shared<GeneralManager>("Jack");

  auto manager = std::make_shared<Manager>("Tom");
  manager->set_successor(general);

  auto director = std::make_shared<Director>("Bob");
  director->set_successor(manager);

  director->ProcessRequest(request);

  return 0;
}