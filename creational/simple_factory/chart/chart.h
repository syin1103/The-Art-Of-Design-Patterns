// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_SIMPLE_FACTORY_CHART_CHART_H_
#define CREATIONAL_SIMPLE_FACTORY_CHART_CHART_H_

#include <iostream>

class Chart {
 public:
  virtual void Display() = 0;
};

class HistogramChart : public Chart {
 public:
  HistogramChart() { std::cout << "Create Histogram Chart..."; }
  void Display() override {
    std::cout << "Displaying Histogram Chart..." << std::endl;
  }
};

class PieChart : public Chart {
 public:
  PieChart() { std::cout << "Create Pie Chart..." << std::endl; }
  void Display() override {
    std::cout << "Displaying Pie Chart..." << std::endl;
  }
};

class LineChart : public Chart {
 public:
  LineChart() { std::cout << "Create Line Chart..." << std::endl; }
  void Display() override {
    std::cout << "Displaying Line Chart..." << std::endl;
  }
};

#endif  // CREATIONAL_SIMPLE_FACTORY_CHART_CHART_H_