// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_FLYWIGHT_MEDIA_DOCUMENT_H_
#define STRUCTURAL_FLYWIGHT_MEDIA_DOCUMENT_H_

#include <string>
#include <vector>

#include "media.h"
#include "media_factory.h"

class Document {
 public:
  void InsertMedia(const std::string& type, const std::string& content,
                   const Position& pos) {
    std::shared_ptr<Media> media = media_factory_.GetMedia(type, content);
    media_references_.emplace_back(media, pos);
  }

  void DisplayAll() const {
    for (const auto& media : media_references_) {
      media.Display();
    }
  }

 private:
  std::vector<MediaReference> media_references_;
  MediaFactory media_factory_;
};

#endif  // STRUCTURAL_FLYWIGHT_MEDIA_DOCUMENT_H_