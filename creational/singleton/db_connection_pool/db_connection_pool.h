// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_SINGLETON_DB_CONNECTION_POOL_CONNECTION_POOL_H_
#define CREATIONAL_SINGLETON_DB_CONNECTION_POOL_CONNECTION_POOL_H_

#include <atomic>
#include <cassert>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

#include "db_connection.h"

constexpr size_t DEFAULT_POOL_SIZE = 2;

using PoolMapType = std::unordered_map<size_t, std::shared_ptr<DBConnection>>;

class DBConnectionPool {
 public:
  ~DBConnectionPool() {}

  /*
   * @attention Non-thread safe, pool should be initialized when main starts
   */
  static void Initialize(size_t size) {
    pool_size_ = size;
    for (size_t i = 0; i < pool_size_; i++) {
      connections_[i] = std::shared_ptr<DBConnection>(new DBConnection(i));
      available_.push_back(i);
    }
  }

  static DBConnectionPool& Instance() {
    static DBConnectionPool instance;
    return instance;
  }

  std::shared_ptr<DBConnection> Acquire() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (available_.empty()) {
      std::cout << "WARNING: No idl connection." << std::endl;
      return nullptr;
    }

    size_t id = available_.back();
    available_.pop_back();

    auto conn = connections_[id];
    assert(!conn->IsInUse());
    conn->set_in_use(true);
    conn->SetLastUsedTime(std::chrono::system_clock::now());
    std::cout << "Acquire connection # " << id << std::endl;
    return conn;
  }

  void Release(size_t id) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!IsExist(id) || !connections_[id]->IsInUse()) {
      return;
    }

    auto conn = connections_[id];
    conn->set_in_use(false);
    conn->SetLastUsedTime(std::chrono::system_clock::now());
    available_.push_back(id);
    std::cout << "Release connection # " << id << std::endl;
    return;
  }

  std::string Status() {
    std::lock_guard<std::mutex> lock(mutex_);

    std::string status = "DBConnectin Pool Status :\n";

    for (const auto& item : connections_) {
      auto conn = item.second;

      auto time = std::chrono::system_clock::to_time_t(conn->GetLastUsedTime());
      if (conn->IsInUse()) {
        status += ("Connection # " + std::to_string(conn->id()) +
                   ": in use, last used time: " + std::ctime(&time));
      } else {
        status += ("Connection # " + std::to_string(conn->id()) +
                   ": available, last used time: " + std::ctime(&time));
      }
    }

    int available = available_.size();
    int use = pool_size_ - available;
    status += ("Total: " + std::to_string(pool_size_) +
               ", in use: " + std::to_string(use) +
               ", available: " + std::to_string(available));

    return status;
  }

  size_t Size() const { return pool_size_; }

  // Just for test
  static void Reset() {
    std::lock_guard<std::mutex> lock(mutex_);
    available_.clear();
    connections_.clear();
    pool_size_ = 0;
  }

 private:
  DBConnectionPool() {
    if (connections_.empty()) {
      Initialize(DEFAULT_POOL_SIZE);
    }
  }

  DBConnectionPool(const DBConnectionPool&) = delete;
  DBConnection& operator=(const DBConnectionPool&) = delete;

  bool IsExist(size_t id) const {
    return connections_.find(id) != connections_.end();
  }

  static PoolMapType connections_;
  static std::vector<size_t> available_;

  static std::mutex mutex_;
  static size_t pool_size_;
};

inline size_t DBConnectionPool::pool_size_ = DEFAULT_POOL_SIZE;
inline PoolMapType DBConnectionPool::connections_;
inline std::vector<size_t> DBConnectionPool::available_;
inline std::mutex DBConnectionPool::mutex_;

#endif  // CREATIONAL_SINGLETON_DB_CONNECTION_POOL_CONNECTION_POOL_H_