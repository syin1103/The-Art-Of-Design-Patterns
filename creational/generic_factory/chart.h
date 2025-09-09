// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_GENERIC_FACTORY_CHART_H_
#define CREATIONAL_GENERIC_FACTORY_CHART_H_

#include <iostream>
#include <memory>

class Chart {
 public:
  virtual void Display() = 0;
};

class HistogramChart : public Chart {
 public:
  HistogramChart() { std::cout << "Create Histogram Chart..." << std::endl; }
  void Display() override {
    std::cout << "Displaying Histogram Chart..." << std::endl;
  }
};

std::unique_ptr<Chart> CreateHisogramChart() {
  return std::make_unique<HistogramChart>();
}

class PieChart : public Chart {
 public:
  PieChart() { std::cout << "Create Pie Chart..." << std::endl; }
  void Display() override {
    std::cout << "Displaying Pie Chart..." << std::endl;
  }

  static std::unique_ptr<Chart> Create() {
    return std::make_unique<PieChart>();
  }
};

class LineChart : public Chart {
 public:
  LineChart() { std::cout << "Create Line Chart..." << std::endl; }
  void Display() override {
    std::cout << "Displaying Line Chart..." << std::endl;
  }

  static std::unique_ptr<Chart> Create() {
    return std::make_unique<LineChart>();
  }
};

#endif  // CREATIONAL_GENERIC_FACTORY_CHART_H_