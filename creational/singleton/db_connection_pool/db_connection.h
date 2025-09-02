// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_SINGLETON_DB_CONNECTION_POOL_CONNECTION_H_
#define CREATIONAL_SINGLETON_DB_CONNECTION_POOL_CONNECTION_H_

#include <chrono>
#include <cstddef>
#include <iostream>
#include <string>
#include <thread>

class DBConnectionPool;

class DBConnection {
  friend class DBConnectionPool;

 public:
  using time_point = std::chrono::system_clock::time_point;

  ~DBConnection() {}

  bool ExecuteQuery(const std::string& query) {
    if (!IsInUse()) {
      std::cout << "ERROR: the connection was not obtained." << std::endl;
      return false;
    }

    std::cout << "Connection # " << id_ << " execute query: " << query
              << std::endl;

    // Emulate query execution
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    return true;
  }

  size_t id() const { return id_; }

  bool IsInUse() const { return in_use_; }
  void set_in_use(bool flag) { in_use_ = flag; }

  time_point GetLastUsedTime() const { return last_used_time_; }
  void SetLastUsedTime(time_point time) { last_used_time_ = time; }

 private:
  DBConnection(size_t id, bool in_use = false) : id_(id), in_use_(in_use) {
    last_used_time_ = std::chrono::system_clock::now();

    // Emulate establishing a database connection
    std::this_thread::sleep_for(std::chrono::milliseconds(80));
  }

  size_t id_;
  bool in_use_;
  time_point last_used_time_;
};

#endif  // CREATIONAL_SINGLETON_DB_CONNECTION_POOL_CONNECTION_H_