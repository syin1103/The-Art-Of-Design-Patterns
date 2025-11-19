// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <iostream>
#include <memory>

#include "airplane.h"

int main() {
  std::cout << "--- Helicopter ---" << std::endl;
  AirCraft helicopter(std::make_unique<VerticalTakeOff>(),
                      std::make_unique<SubSonicFly>());
  helicopter.TakeOff();
  helicopter.Fly();

  std::cout << "--- Air Plane ---" << std::endl;
  AirCraft airplane(std::make_unique<LongDistanceTakeOff>(),
                    std::make_unique<SubSonicFly>());
  airplane.TakeOff();
  airplane.Fly();

  std::cout << "--- Fighter ---" << std::endl;
  AirCraft fighter(std::make_unique<LongDistanceTakeOff>(),
                   std::make_unique<SuperSonicFly>());
  fighter.TakeOff();
  fighter.Fly();

  std::cout << "--- Harrier ---" << std::endl;
  AirCraft harrier(std::make_unique<VerticalTakeOff>(),
                   std::make_unique<SuperSonicFly>());
  harrier.TakeOff();
  harrier.Fly();

  return 0;
}