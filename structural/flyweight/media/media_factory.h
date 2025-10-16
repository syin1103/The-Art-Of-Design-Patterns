// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_FLYWIGHT_MEDIA_MEDIA_FACTORY_H_
#define STRUCTURAL_FLYWIGHT_MEDIA_MEDIA_FACTORY_H_

#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "media.h"

class MediaFactory {
 public:
  std::shared_ptr<Media> GetMedia(const std::string& type,
                                  const std::string& content) {
    std::string key = type + ":" + content;
    if (media_pool_.find(key) == media_pool_.end()) {
      if (type == "image") {
        media_pool_[key] = std::make_shared<Image>(content);
      } else if (type == "animation") {
        media_pool_[key] = std::make_shared<Animation>(content);
      } else if (type == "video") {
        media_pool_[key] = std::make_shared<Video>(content);
      } else {
        throw std ::runtime_error("Unknow type");
      }
    }
    return media_pool_[key];
  }

 private:
  std::unordered_map<std::string, std::shared_ptr<Media>> media_pool_;
};

#endif  // STRUCTURAL_FLYWIGHT_MEDIA_MEDIA_FACTORY_H_