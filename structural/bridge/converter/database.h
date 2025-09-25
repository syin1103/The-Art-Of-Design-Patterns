// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_BRIDGE_CONVERTER_DATABASE_H_
#define STRUCTURAL_BRIDGE_CONVERTER_DATABASE_H_

#include <iostream>
#include <string>

class Database {
 public:
  virtual ~Database() {}
  virtual void Connect(const std::string& target) = 0;
  virtual void Disconnect() = 0;
  virtual std::string ExcuteQuery(const std::string& sql) = 0;

  virtual std::string name() const = 0;
};

class MySQLDB : public Database {
 public:
  virtual ~MySQLDB() {};

  void Connect(const std::string& target) override {
    std::cout << "Connect to MySQL Database: " << target << std::endl;
  }

  void Disconnect() override {
    std::cout << "Disconnect to MySQL Database" << std::endl;
  }

  std::string ExcuteQuery(const std::string& sql) override {
    return "mysql: " + sql;
  };

  std::string name() const override { return "MySQL"; }
};

class OracleDB : public Database {
 public:
  virtual ~OracleDB() {};

  void Connect(const std::string& target) override {
    std::cout << "Connect to Oracle Database: " << target << std::endl;
  }

  void Disconnect() override {
    std::cout << "Disconnect to Oracle Database" << std::endl;
  }

  std::string ExcuteQuery(const std::string& sql) override {
    return "oracle: " + sql;
  }

  std::string name() const override { return "Oracle"; }
};

#endif  // STRUCTURAL_BRIDGE_CONVERTER_DATABASE_H_