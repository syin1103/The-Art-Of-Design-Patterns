// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_TEMPLATE_DB_OPERATOR_DB_OPERATOR_H_
#define BEHAVIORAL_TEMPLATE_DB_OPERATOR_DB_OPERATOR_H_

#include <iostream>
#include <string>

enum class Type { DB_UPDATE = 0, DB_QUERY };

class DBOperator {
 public:
  virtual ~DBOperator() {};

  void Execute(const std::string& sql, Type type) {
    Connect();
    Open();

    if (type == Type::DB_UPDATE) {
      Query();
    } else if (type == Type::DB_UPDATE) {
      Update();
    } else {
      return;
    }

    Close();
  }

 private:
  void Update() { std::cout << "Update DataBase..." << std::endl; }
  void Query() { std::cout << "Update DataBase..." << std::endl; }

  virtual void Connect() = 0;
  virtual void Open() = 0;
  virtual void Close() = 0;
};

class JDBCODBCBridge : public DBOperator {
 private:
  void Connect() override { std::cout << "Connect JDBC-ODBC ..." << std::endl; }
  void Open() override { std::cout << "Open JDBC-ODBC..." << std::endl; }
  void Close() override { std::cout << "Close JDBC-ODBC..." << std::endl; }
};

class VendorDriver : public DBOperator {
 private:
  void Connect() override {
    std::cout << "Connect VendorDriver ..." << std::endl;
  }
  void Open() override { std::cout << "Open VendorDriver..." << std::endl; }
  void Close() override { std::cout << "Close VendorDriver..." << std::endl; }
};

class ConnectionPool : public DBOperator {
 private:
  void Connect() override {
    std::cout << "Connect ConnectionPool..." << std::endl;
  }
  void Open() override { std::cout << "Open ConnectionPool..." << std::endl; }
  void Close() override {
    std::cout << "Close JConnectionPool..." << std::endl;
  }
};

#endif  // BEHAVIORAL_TEMPLATE_DB_OPERATOR_DB_OPERATOR_H_