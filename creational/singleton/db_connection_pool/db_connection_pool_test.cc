// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "db_connection_pool.h"

int main() {
  DBConnectionPool::Initialize(5);

  DBConnectionPool& pool = DBConnectionPool::Instance();

  auto excution = []() {
    DBConnectionPool& pool = DBConnectionPool::Instance();
    for (int i = 0; i < 10; i++) {
      std::string query = ("SELECT* FROM products " + std::to_string(i));
      auto conn = pool.Acquire();
      if (conn != nullptr) {
        conn->ExecuteQuery(query);
      }
      pool.Release(conn->id());
    }
  };

  std::thread thread1(excution);
  std::thread thread2(excution);
  std::thread thread3(excution);
  std::thread thread4(excution);
  std::thread thread5(excution);

  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();
  thread5.join();

  std::cout << pool.Status() << std::endl;
  return 0;
}