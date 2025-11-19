// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <memory>

#include "movie.h"

int main() {
  MovieTicket ticket(100);
  std::cout << ticket.GetPrice() << std::endl;

  ticket.SetDiscount(std::make_unique<StudentDiscount>());
  std::cout << ticket.GetPrice() << std::endl;

  ticket.SetDiscount(std::make_unique<ChildrenDiscount>());
  std::cout << ticket.GetPrice() << std::endl;

  ticket.SetDiscount(std::make_unique<VIPDiscount>());
  std::cout << ticket.GetPrice() << std::endl;

  return 0;
}
