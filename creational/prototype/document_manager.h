// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_PROTOTYPE_DOCUMENT_MANAGER_H_
#define CREATIONAL_PROTOTYPE_DOCUMENT_MANAGER_H_

#include <string>
#include <unordered_map>

#include "official_document.h"

class DocumentManager {
  using OfficialDocumentPtr = std::unique_ptr<OfficialDocument>;

 public:
  ~DocumentManager() {}

  static DocumentManager& Instance() {
    static DocumentManager instance;
    return instance;
  }

  void AddDocument(const std::string& type, OfficialDocumentPtr doc) {
    documents_[type] = std::move(doc);
  }

  OfficialDocumentPtr GetDocument(const std::string& type) const {
    auto it = documents_.find(type);
    if (it == documents_.end()) {
      return nullptr;
    }
    return (it->second)->Clone();
  }

  void RemoveDocument(const std::string& type) {
    if (documents_.find(type) != documents_.end()) {
      documents_.erase(type);
    }
  }

 private:
  DocumentManager() {};
  DocumentManager(const DocumentManager&) = delete;
  DocumentManager& operator=(const DocumentManager&) = delete;

  std::unordered_map<std::string, OfficialDocumentPtr> documents_;
};

#endif  // CREATIONAL_PROTOTYPE_DOCUMENT_MANAGER_H_