// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <memory>

#include "visitor.h"

int main() {
  auto fulltime = std::make_unique<FulltimeEpy>("Tom");
  auto parttime = std::make_unique<ParttimeEpy>("Lucy");

  fulltime->set_weekly_wage(20);
  parttime->set_hour_wage(10);

  fulltime->set_work_time(100);
  parttime->set_work_time(30);

  EmployeeList employees;
  employees.AddEmployee(std::move(fulltime));
  employees.AddEmployee(std::move(parttime));

  FADepartment fa;
  HRDepartment hr;

  employees.Accept(&fa);
  employees.Accept(&hr);

  return 0;
}