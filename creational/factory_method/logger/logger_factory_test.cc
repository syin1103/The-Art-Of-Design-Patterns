// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "logger_factory.h"

#include <iostream>
#include <memory>

#include "logger.h"

int main() {
  DBLoggerFactory db_factory;
  std::unique_ptr<Logger> db_logger = db_factory.CreateLogger();
  db_logger->Log("Hello DBLogger...");

  FileLoggerFactory file_factory;
  std::unique_ptr<Logger> file_logger = file_factory.CreateLogger();
  file_logger->Log("Hello FileLogger...");

  return 0;
}