// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "load_balancer.h"

#include <iostream>

int main() {
  LoadBalancer& balancer1 = LoadBalancer::Instance();
  LoadBalancer& balancer2 = LoadBalancer::Instance();
  LoadBalancer& balancer3 = LoadBalancer::Instance();
  LoadBalancer& balancer4 = LoadBalancer::Instance();

  if ((&balancer1 == &balancer2) && (&balancer1 == &balancer3) &&
      (&balancer1 == &balancer4)) {
    std::cout << "The LoadBalancer is unique." << std::endl;
  }

  balancer1.AddServer("Server1");
  balancer2.AddServer("Server2");
  balancer3.AddServer("Server3");
  balancer4.AddServer("Server4");

  for (int i = 0; i < 10; i++) {
    std::string server = balancer1.GetServer();
    std::cout << "Dispatching request to: " << server << std::endl;
  }

  return 0;
}