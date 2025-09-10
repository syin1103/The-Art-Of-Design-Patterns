// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "official_document.h"

#include "document_manager.h"

int main() {
  DocumentManager& doc_manager = DocumentManager::Instance();

  doc_manager.AddDocument("FAR", std::make_unique<FARDocument>());
  doc_manager.AddDocument("SRS", std::make_unique<SRSDocument>());

  auto far1 = doc_manager.GetDocument("FAR");
  auto far2 = doc_manager.GetDocument("FAR");

  auto srs1 = doc_manager.GetDocument("SRS");

  far1->Display();
  far2->Display();
  srs1->Display();

  doc_manager.RemoveDocument("FAR");
  doc_manager.RemoveDocument("SRS");

  return 0;
}