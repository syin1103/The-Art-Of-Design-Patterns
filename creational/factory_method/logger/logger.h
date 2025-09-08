// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_FACTORY_METHOD_LOGGER_H_
#define CREATIONAL_FACTORY_METHOD_LOGGER_H_

#include <iostream>
#include <string>

class Logger {
 public:
  virtual void Log(const std::string& msg) = 0;
};

class DBLogger : public Logger {
 public:
  DBLogger() { std::cout << "Create DBLogger..." << std::endl; }
  void Log(const std::string& msg) override {
    std::cout << "DataBase logging..." << std::endl;
  }
};

class FileLogger : public Logger {
 public:
  FileLogger() { std::cout << "Create FileLogger..." << std::endl; }
  void Log(const std::string& msg) override {
    std::cout << "File logging..." << std::endl;
  }
};

#endif  // CREATIONAL_FACTORY_METHOD_LOGGER_H_