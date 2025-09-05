// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "chart_factory.h"

#include <iostream>

#include "chart.h"
#include "config_utils.h"

int main() {
  const std::string config_file = "./config.json";

  json config = ConfigUtils::LoadConfig(config_file);
  std::cout << ConfigUtils::GetConfigValue(config, "type") << std::endl;

  ChartFactory chart_factory;
  auto chart = chart_factory.CreateFromConfig(config_file);
  chart->Display();
  return 0;
}