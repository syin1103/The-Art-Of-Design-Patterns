// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_OBSERVER_STOCK_STOCK_H_
#define BEHAVIORAL_OBSERVER_STOCK_STOCK_H_

#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>

class IInvestor {
 public:
  explicit IInvestor(const std::string& name) : name_(name) {}
  virtual ~IInvestor() {}
  virtual void Update(const std::string& name, double price) const = 0;

 protected:
  std::string name_;
};

class ConcreteInvestor : public IInvestor {
 public:
  explicit ConcreteInvestor(const std::string& name) : IInvestor(name) {}
  virtual ~ConcreteInvestor() {}

  void Update(const std::string& name, double price) const override {
    std::cout << "Investor: " << name_ << ", Stock : " << name
              << ", New Price : " << price << std::endl;
  }
};

class IStock {
 public:
  IStock(const std::string& name, double price = 0.0)
      : name_(name), price_(price) {}
  virtual ~IStock() {}

  std::string name() const { return name_; }
  double price() const { return price_; }
  virtual void set_price(double price) { price_ = price; }

  void Attach(std::shared_ptr<IInvestor> investor) {
    investors_.insert(investor);
  }

  void Remove(std::shared_ptr<IInvestor> investor) {
    investors_.erase(investor);
  }

  void Notify(const std::string& name, double price) const {
    for (const auto& investor : investors_) {
      investor->Update(name, price);
    }
  };

 protected:
  double price_;
  std::string name_;
  std::unordered_set<std::shared_ptr<IInvestor>> investors_;
};

class ConcreteStock : public IStock {
 public:
  ConcreteStock(const std::string& name, double price = 0.0)
      : IStock(name, price) {}
  virtual ~ConcreteStock() {}

  void set_price(double price) override {
    double change = std::abs(price - price_) / price_;
    price_ = price;
    if (change >= 0.5) {
      Notify(name_, price_);
    }
  }
};

#endif  // BEHAVIORAL_OBSERVER_STOCK_STOCK_H_