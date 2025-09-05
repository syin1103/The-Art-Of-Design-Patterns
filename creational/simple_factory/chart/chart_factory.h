// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_SIMPLE_FACTORY_CHART_CHART_FACTORY_H_
#define CREATIONAL_SIMPLE_FACTORY_CHART_CHART_FACTORY_H_

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "chart.h"
#include "config_utils.h"

class ChartFactory {
  using Creator = std::function<std::unique_ptr<Chart>()>;

 public:
  ChartFactory() {
    RegisterCreator("Histogram",
                    []() { return std::make_unique<HistogramChart>(); });
    RegisterCreator("Pie", []() { return std::make_unique<PieChart>(); });
    RegisterCreator("Line", []() { return std::make_unique<LineChart>(); });
  };

  void RegisterCreator(const std::string& type, Creator creator) {
    assert(creators_.find(type) == creators_.end());
    creators_[type] = std::move(creator);
  }

  std::unique_ptr<Chart> Create(const std::string& type) {
    auto it = creators_.find(type);
    if (it != creators_.end()) {
      return it->second();
    }
    return nullptr;
  }

  std::unique_ptr<Chart> CreateFromConfig(const std::string& filename) {
    json config = ConfigUtils::LoadConfig(filename);
    std::string type = ConfigUtils::GetConfigValue(config, "type");
    return Create(type);
  }

 private:
  std::unordered_map<std::string, Creator> creators_;
};

#endif  // CREATIONAL_SIMPLE_FACTORY_CHART_CHART_FACTORY_H_