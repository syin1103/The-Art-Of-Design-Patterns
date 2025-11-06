// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_CHAIN_PURCHASE_APPROVER_H_
#define BEHAVIORAL_CHAIN_PURCHASE_APPROVER_H_

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

class PurchaseRequese {
 public:
  PurchaseRequese(double amount, int number, const std::string& purpose)
      : amount_(amount), number_(number), purpose_(purpose) {}

  void set_amount(double amount) { amount_ = amount; }
  double amount() const { return amount_; }

  void set_number(int number) { number_ = number; }
  int number() const { return number_; }

  void set_purpose(const std::string& purpose) { purpose_ = purpose; }
  std::string purpose() const { return purpose_; }

 private:
  double amount_;
  int number_;
  std::string purpose_;
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

  virtual void ProcessRequest(const PurchaseRequese& request) = 0;

 protected:
  std::string name_;
  std::shared_ptr<Approver> successor_ = nullptr;
};

class Director : public Approver {
 public:
  Director(const std::string& name) : Approver(name) {}
  virtual ~Director() {}

  void ProcessRequest(const PurchaseRequese& request) override {
    if (request.amount() < 50000) {
      std::cout << "Director: " << name() << ", amount: " << request.amount()
                << ", number: " << request.number()
                << ", purpose: " << request.purpose() << std::endl;
    } else {
      assert(successor_ != nullptr);
      successor_->ProcessRequest(request);
    }
  }
};

class VicePresident : public Approver {
 public:
  VicePresident(const std::string& name) : Approver(name) {}
  virtual ~VicePresident() {}

  void ProcessRequest(const PurchaseRequese& request) override {
    if (request.amount() < 100000) {
      std::cout << "VicePresident: " << name()
                << ", amount: " << request.amount()
                << ", number: " << request.number()
                << ", purpose: " << request.purpose() << std::endl;
    } else {
      assert(successor_ != nullptr);
      successor_->ProcessRequest(request);
    }
  }
};

class President : public Approver {
 public:
  President(const std::string& name) : Approver(name) {}
  virtual ~President() {}

  void ProcessRequest(const PurchaseRequese& request) override {
    if (request.amount() < 500000) {
      std::cout << "President: " << name() << ", amount: " << request.amount()
                << ", number: " << request.number()
                << ", purpose: " << request.purpose() << std::endl;
    } else {
      assert(successor_ != nullptr);
      successor_->ProcessRequest(request);
    }
  }
};

class Congress : public Approver {
 public:
  Congress(const std::string& name) : Approver(name) {}
  virtual ~Congress() {}

  void ProcessRequest(const PurchaseRequese& request) override {
    std::cout << "Congress: " << name() << ", amount: " << request.amount()
              << ", number: " << request.number()
              << ", purpose: " << request.purpose() << std::endl;
  }
};

#endif  // BEHAVIORAL_CHAIN_PURCHASE_APPROVER_H_