// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_FACTORY_METHOD_IMAGE_READER_IMAGE_READER_FACTORY_H_
#define CREATIONAL_FACTORY_METHOD_IMAGE_READER_IMAGE_READER_FACTORY_H_

#include <memory>

#include "image_reader.h"

class ImageReaderFactory {
 public:
  virtual std::unique_ptr<ImageReader> CreateReader() = 0;
};

class GifReaderFactory : public ImageReaderFactory {
 public:
  std::unique_ptr<ImageReader> CreateReader() {
    return std::make_unique<GifReader>();
  }
};

class PngReaderFactory : public ImageReaderFactory {
 public:
  std::unique_ptr<ImageReader> CreateReader() {
    return std::make_unique<PngReader>();
  }
};

class JpgReaderFactory : public ImageReaderFactory {
 public:
  std::unique_ptr<ImageReader> CreateReader() {
    return std::make_unique<JpgReader>();
  }
};

#endif  // CREATIONAL_FACTORY_METHOD_IMAGE_READER_IMAGE_READER_FACTORY_H_