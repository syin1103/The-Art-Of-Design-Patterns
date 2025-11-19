// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_STRATEGY_MOVIE_MOVIE_H_
#define BEHAVIORAL_STRATEGY_MOVIE_MOVIE_H_

#include <iostream>
#include <memory>

class Discount {
 public:
  virtual ~Discount() {}
  virtual double Caculate(double price) = 0;
};

class StudentDiscount : public Discount {
 public:
  double Caculate(double price) override {
    std::cout << "Student Ticket..." << std::endl;
    return price * 0.8;
  }
};

class ChildrenDiscount : public Discount {
 public:
  double Caculate(double price) override {
    std::cout << "Children Ticket..." << std::endl;
    if (price >= 20) {
      price -= 10;
    }
    return price;
  }
};

class VIPDiscount : public Discount {
 public:
  double Caculate(double price) override {
    std::cout << "VIP Ticket..." << std::endl;
    std::cout << "Add Score..." << std::endl;
    return price * 0.5;
  }
};

class MovieTicket {
 public:
  MovieTicket(double price) : price_(price) {}

  void SetDiscount(std::unique_ptr<Discount> discount) {
    discount_ = std::move(discount);
  }

  void SetPrice(double price) { price_ = price; }
  double GetPrice() {
    if (discount_ != nullptr) {
      return discount_->Caculate(price_);
    }
    return price_;
  }

 private:
  double price_;
  std::unique_ptr<Discount> discount_;
};

#endif  // BEHAVIORAL_STRATEGY_MOVIE_MOVIE_H_