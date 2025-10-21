// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_PROXY_SEARCHER_SEARCHER_H_
#define STRUCTURAL_PROXY_SEARCHER_SEARCHER_H_

#include <iostream>
#include <memory>
#include <string>

class Searcher {
 public:
  Searcher() = default;
  virtual ~Searcher() = default;
  virtual std::string DoSearch(const std::string& user_id,
                               const std::string& key) = 0;
};

class RealSearcher : public Searcher {
 public:
  std::string DoSearch(const std::string& user_id,
                       const std::string& key) override {
    return user_id + "-" + key;
  }
};

class SearcherProxy : public Searcher {
 public:
  SearcherProxy() : real_searcher_(std::make_unique<RealSearcher>()) {}
  virtual ~SearcherProxy() {}

  std::string DoSearch(const std::string& user_id,
                       const std::string& key) override {
    if (Validate(user_id)) {
      Log(user_id, key);
      return user_id + "-" + key;
    }
    return "";
  }

 private:
  void Log(const std::string& user_id, const std::string& key) {
    std::cout << "Log: " << user_id + ", " << key << std::endl;
  }

  bool Validate(const std::string& user_id) {
    std::cout << "validate: " << user_id << std::endl;
    return true;
  }

  std::unique_ptr<RealSearcher> real_searcher_;
};

#endif  // STRUCTURAL_PROXY_SEARCHER_SEARCHER_H_