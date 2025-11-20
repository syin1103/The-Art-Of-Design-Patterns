// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <iostream>

#include "db_operator.h"

int main() {
  std::string sql = "query_sql_test";

  JDBCODBCBridge jdbc_odbc;
  jdbc_odbc.Execute(sql, Type::DB_QUERY);
  jdbc_odbc.Execute(sql, Type::DB_UPDATE);

  std::cout << "------ " << std::endl;

  VendorDriver vendor;
  vendor.Execute(sql, Type::DB_QUERY);
  vendor.Execute(sql, Type::DB_UPDATE);
  return 0;
}