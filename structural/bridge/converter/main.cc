// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <string>

#include "converter.h"
#include "database.h"

int main() {
  auto mysql = std::make_unique<MySQLDB>();
  auto oracle = std::make_unique<OracleDB>();
  auto txt = ConverterFactory::CreateConverter("TXT", std::move(mysql), "test");
  txt->ConvertData("select data");

  auto pdf =
      ConverterFactory::CreateConverter("PDF", std::move(oracle), "test");
  pdf->ConvertData("select data");
  return 0;
}