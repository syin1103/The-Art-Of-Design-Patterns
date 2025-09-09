// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_GENERIC_FACTORY_GENERIC_FACTORY_H_
#define CREATIONAL_GENERIC_FACTORY_GENERIC_FACTORY_H_

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

template <typename T>
class GenericFactory {
  using Creator = std::function<std::unique_ptr<T>()>;

 public:
  static void Regist(const std::string& type, Creator&& creator) {
    registry_[type] = std::move(creator);
  }

  static std::unique_ptr<T> Create(const std::string& type) {
    auto it = registry_.find(type);
    if (it != registry_.end()) {
      return it->second();
    }
    return nullptr;
  }

 private:
  static std::unordered_map<std::string, Creator> registry_;
};

template <typename T>
std::unordered_map<std::string, typename GenericFactory<T>::Creator>
    GenericFactory<T>::registry_;

#define FACTORY_REGIST(BASECLASS, TYPE, CREATOR) \
  GenericFactory<BASECLASS>::Regist(#TYPE, CREATOR)

#define FACTORY_CREATOR(BASECLASS, TYPE) \
  GenericFactory<BASECLASS>::Create(#TYPE)

#endif  // CREATIONAL_GENERIC_FACTORY_GENERIC_FACTORY_H_