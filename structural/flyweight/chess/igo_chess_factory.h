// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_FLYWIGHT_CHESS_IGO_CHESS_FACTORY_H_
#define STRUCTURAL_FLYWIGHT_CHESS_IGO_CHESS_FACTORY_H_

#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "igo_chess.h"

class IgoChessFactory {
 public:
  ~IgoChessFactory() = default;

  static IgoChessFactory& Instance() {
    static IgoChessFactory instance;
    return instance;
  }

  std::shared_ptr<IgoChess> Create(const std::string& type) {
    if (pool_.find(type) == pool_.end()) {
      throw std::runtime_error("Unknown type");
    }
    return pool_[type];
  }

 private:
  IgoChessFactory() {
    pool_.emplace("black", std::make_shared<BlackIgoChess>());
    pool_.emplace("white", std::make_shared<WhiteIgoChess>());
  }

  IgoChessFactory(const IgoChessFactory&) = delete;
  IgoChessFactory& operator=(const IgoChessFactory&) = delete;

  std::unordered_map<std::string, std::shared_ptr<IgoChess>> pool_;
};

#endif  // STRUCTURAL_FLYWIGHT_CHESS_IGO_CHESS_FACTORY_H_