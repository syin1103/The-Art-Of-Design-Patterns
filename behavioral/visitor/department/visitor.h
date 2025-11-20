// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_VISITOR_DEPARTMENT_VISITOR_H_
#define BEHAVIORAL_VISITOR_DEPARTMENT_VISITOR_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class FulltimeEpy;
class ParttimeEpy;

class Department {
 public:
  virtual ~Department() {}
  virtual void Visit(FulltimeEpy* employee) = 0;
  virtual void Visit(ParttimeEpy* employee) = 0;
};

class FADepartment : public Department {
 public:
  void Visit(FulltimeEpy* employee) override;
  void Visit(ParttimeEpy* employee) override;
};

class HRDepartment : public Department {
 public:
  void Visit(FulltimeEpy* employee) override;
  void Visit(ParttimeEpy* employee) override;
};

class Employee {
 public:
  virtual void Accept(Department* department) = 0;
};

class FulltimeEpy : public Employee {
 public:
  FulltimeEpy(const std::string& name) : name_(name) {}
  void Accept(Department* department) override { department->Visit(this); }

  std::string name() const { return name_; }

  double weekly_wage() const { return weekly_wage_; }
  void set_weekly_wage(double value) { weekly_wage_ = value; }

  int work_time() const { return work_time_; }
  void set_work_time(int value) { work_time_ = value; }

 private:
  std::string name_;
  double weekly_wage_ = 0.0;
  int work_time_ = 0.0;
};

class ParttimeEpy : public Employee {
 public:
  ParttimeEpy(const std::string& name) : name_(name) {}
  void Accept(Department* department) override { department->Visit(this); }

  std::string name() const { return name_; }

  double hour_wage() const { return hour_wage_; }
  void set_hour_wage(double value) { hour_wage_ = value; }

  int work_time() const { return work_time_; }
  void set_work_time(int value) { work_time_ = value; }

 private:
  std::string name_;
  double hour_wage_ = 0.0;
  int work_time_ = 0.0;
};

class EmployeeList {
 public:
  void AddEmployee(std::unique_ptr<Employee> employee) {
    employees_.emplace_back(std::move(employee));
  }

  void Accept(Department* department) {
    for (const auto& employee : employees_) {
      employee->Accept(department);
    }
  }

 private:
  std::vector<std::unique_ptr<Employee>> employees_;
};

inline void HRDepartment::Visit(FulltimeEpy* employee) {
  int work_time = employee->work_time();
  std::cout << "Fulltime: " << employee->name()
            << ", Real worktime: " << work_time << std::endl;
  if (work_time > 40) {
    std::cout << "Overtime: " << work_time - 40 << std::endl;
  } else if (work_time < 40) {
    std::cout << "Leave: " << 40 - work_time << std::endl;
  }
}

inline void HRDepartment::Visit(ParttimeEpy* employee) {
  std::cout << "Parttime: " << employee->name()
            << ", Real worktime: " << employee->work_time() << std::endl;
}

inline void FADepartment::Visit(FulltimeEpy* employee) {
  double week_wage = employee->weekly_wage();
  int work_time = employee->work_time();
  if (work_time > 40) {
    week_wage = week_wage + (work_time - 40) * 100;
  } else if (work_time < 40) {
    week_wage = week_wage - (40 - work_time) * 80;
    if (week_wage < 0) {
      week_wage = 0;
    }
  }
  std::cout << "Fulltime: " << employee->name() << ", " << week_wage
            << std::endl;
}

inline void FADepartment::Visit(ParttimeEpy* employee) {
  double wage = employee->hour_wage() * employee->work_time();
  std::cout << "Parttime: " << employee->name() << ", " << wage << std::endl;
}

#endif  // BEHAVIORAL_VISITOR_DEPARTMENT_VISITOR_H_