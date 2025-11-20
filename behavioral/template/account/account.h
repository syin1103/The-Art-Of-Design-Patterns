// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_TEMPLATE_ACCOUNT_ACCOUNT_H_
#define BEHAVIORAL_TEMPLATE_ACCOUNT_ACCOUNT_H_

#include <iostream>
#include <string>

class Account {
 public:
  virtual ~Account() {}

  void Handle(const std::string& account, const std::string& password) {
    if (!Validate(account, password)) {
      std::cout << "Account or password error..." << std::endl;
      return;
    }

    CaculateInterest();
    Display();
  }

 private:
  void Display() { std::cout << "Display Interest..." << std::endl; }

  bool Validate(const std::string& account, const std::string& password) {
    std::cout << "Account: " << account << ", password: " << password
              << std::endl;

    if (account == "ZhangWuji" && password == "123456") {
      return true;
    }
    return false;
  }

  virtual void CaculateInterest() = 0;
};

class CurrAccount : public Account {
 public:
  virtual ~CurrAccount() {}
  void CaculateInterest() override {
    std::cout << "CurrAccount Interest..." << std::endl;
  }
};

class SaveAccount : public Account {
 public:
  virtual ~SaveAccount() {}
  void CaculateInterest() override {
    std::cout << "SaveAccount Interest..." << std::endl;
  }
};

#endif  // BEHAVIORAL_TEMPLATE_ACCOUNT_ACCOUNT_H_