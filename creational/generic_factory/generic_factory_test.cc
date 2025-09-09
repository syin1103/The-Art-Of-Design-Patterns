// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "generic_factory.h"

#include "chart.h"

int main() {
  FACTORY_REGIST(Chart, Histogram, CreateHisogramChart);
  FACTORY_REGIST(Chart, Pie, PieChart::Create);
  FACTORY_REGIST(Chart, Line, LineChart::Create);

  auto histogram = FACTORY_CREATOR(Chart, Histogram);
  auto pie = GenericFactory<Chart>::Create("Pie");
  auto line = GenericFactory<Chart>::Create("Line");

  histogram->Display();
  pie->Display();
  line->Display();

  return 0;
}