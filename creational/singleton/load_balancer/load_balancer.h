// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_SINGLETON_LOAD_BALANCER_LOAD_BALANCER_H_
#define CREATIONAL_SINGLETON_LOAD_BALANCER_LOAD_BALANCER_H_

#include <algorithm>
#include <list>
#include <stdexcept>
#include <string>

class LoadBalancer {
 public:
  static LoadBalancer& Instance() {
    static LoadBalancer instance;
    return instance;
  }

  bool IsEmpty() const { return servers_.empty(); }
  bool Size() const { return servers_.size(); }

  void AddServer(const std::string& server) { servers_.push_back(server); }
  void RemoveServer(const std::string& server) { servers_.remove(server); }

  std::string GetServer() {
    if (IsEmpty()) {
      throw std::runtime_error("LoadBalancer has no server.");
    }

    size_t n = rand() % servers_.size();
    auto it = servers_.begin();
    std::advance(it, n);
    return *it;
  }

 private:
  LoadBalancer() = default;
  ~LoadBalancer() = default;

  LoadBalancer(const LoadBalancer&) = delete;
  LoadBalancer& operator=(const LoadBalancer&) = delete;

  std::list<std::string> servers_;
};

#endif  // CREATIONAL_SINGLETON_LOAD_BALANCER_LOAD_BALANCER_H_