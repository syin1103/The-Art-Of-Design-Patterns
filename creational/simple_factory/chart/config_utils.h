// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_SIMPLE_FACTORY_CHART_CONFIG_UTILS_H_
#define CREATIONAL_SIMPLE_FACTORY_CHART_CONFIG_UTILS_H_

#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class ConfigUtils {
 public:
  static json LoadConfig(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
      throw std::runtime_error("Can not open config file: " + filename);
    }

    json config;
    ifs >> config;
    return config;
  }

  static std::string GetConfigValue(const json& config,
                                    const std::string& key) {
    if (config.contains(key) && config[key].is_string()) {
      return config[key].get<std::string>();
    }
    return {};
  }
};

#endif  // CREATIONAL_SIMPLE_FACTORY_CHART_CONFIG_UTILS_H_