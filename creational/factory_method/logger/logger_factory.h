// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_FACTORY_METHOD_LOGGER_FACTORY_H_
#define CREATIONAL_FACTORY_METHOD_LOGGER_FACTORY_H_

#include <memory>

#include "logger.h"

class LoggerFactory {
 public:
  virtual std::unique_ptr<Logger> CreateLogger() = 0;
};

class DBLoggerFactory : public LoggerFactory {
 public:
  std::unique_ptr<Logger> CreateLogger() override {
    /*
     * Connect to database...
     */
    std::unique_ptr<Logger> logger = std::make_unique<DBLogger>();

    /*
     * Initialize logger...
     */
    return logger;
  }
};

class FileLoggerFactory : public LoggerFactory {
 public:
  std::unique_ptr<Logger> CreateLogger() override {
    /*
     * Other preparations
     */
    std::unique_ptr<Logger> logger = std::make_unique<FileLogger>();

    /*
     * Initialize logger...
     */
    return logger;
  }
};

#endif  // CREATIONAL_FACTORY_METHOD_LOGGER_FACTORY_H_
