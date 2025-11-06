// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_CHAIN_LEAVE_APPROVER_H_
#define BEHAVIORAL_CHAIN_LEAVE_APPROVER_H_

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

class LeaveRequese {
 public:
  LeaveRequese(int days, const std::string& reason)
      : days_(days), reason_(reason) {}

  void set_days(int days) { days_ = days; }
  int days() const { return days_; }

  void set_reason(const std::string& reason) { reason_ = reason; }
  std::string reason() const { return reason_; }

 private:
  int days_;
  std::string reason_;
};

class Approver {
 public:
  Approver(const std::string& name) : name_(name) {}
  virtual ~Approver() = default;

  std::shared_ptr<Approver> successor() const { return successor_; }
  void set_successor(const std::shared_ptr<Approver>& successor) {
    successor_ = successor;
  }

  std::string name() const { return name_; }

  virtual void ProcessRequest(const LeaveRequese& request) = 0;

 protected:
  std::string name_;
  std::shared_ptr<Approver> successor_ = nullptr;
};

class Director : public Approver {
 public:
  Director(const std::string& name) : Approver(name) {}
  virtual ~Director() {}

  void ProcessRequest(const LeaveRequese& request) override {
    if (request.days() <= 3) {
      std::cout << "Director: " << name() << ", days: " << request.days()
                << ", reason: " << request.reason() << std::endl;
    } else {
      assert(successor_ != nullptr);
      successor_->ProcessRequest(request);
    }
  }
};

class Manager : public Approver {
 public:
  Manager(const std::string& name) : Approver(name) {}
  virtual ~Manager() {}

  void ProcessRequest(const LeaveRequese& request) override {
    if (request.days() <= 10) {
      std::cout << "Manager: " << name() << ", days: " << request.days()
                << ", reason: " << request.reason() << std::endl;
    } else {
      assert(successor_ != nullptr);
      successor_->ProcessRequest(request);
    }
  }
};

class GeneralManager : public Approver {
 public:
  GeneralManager(const std::string& name) : Approver(name) {}
  virtual ~GeneralManager() {}

  void ProcessRequest(const LeaveRequese& request) override {
    if (request.days() <= 30) {
      std::cout << "GeneralManager: " << name() << ", days: " << request.days()
                << ", reason: " << request.reason() << std::endl;
    } else {
      std::cout << "Reject, days > 30" << std::endl;
    }
  }
};

#endif  // BEHAVIORAL_CHAIN_LEAVE_APPROVER_H_