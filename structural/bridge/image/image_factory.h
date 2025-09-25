// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_BRIDGE_IMAGE_IMAGE_FACTORY_H_
#define STRUCTURAL_BRIDGE_IMAGE_IMAGE_FACTORY_H_

#include <memory>

#include "image.h"

class ImageFactory {
 public:
  static std::unique_ptr<Image> CreateImage(const std::string& type) {
    if (type == "JPG") {
      return std::make_unique<JPGImage>();
    } else if (type == "PNG") {
      return std::make_unique<PNGImage>();
    } else if (type == "BMP") {
      return std::make_unique<BMPImage>();
    } else {
      throw std::invalid_argument("Unsupported Image type: " + type);
    }
  }
};

#endif  // STRUCTURAL_BRIDGE_IMAGE_IMAGE_FACTORY_H_