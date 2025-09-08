// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <functional>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include "image_reader.h"
#include "image_reader_factory.h"

class ImageReaderCreator {
  using Creator = std::function<std::unique_ptr<ImageReaderFactory>()>;

 public:
  ImageReaderCreator() {
    RegisterFactory("gif", []() -> std::unique_ptr<GifReaderFactory> {
      return std::make_unique<GifReaderFactory>();
    });

    RegisterFactory("png", []() -> std::unique_ptr<PngReaderFactory> {
      return std::make_unique<PngReaderFactory>();
    });

    RegisterFactory("jpg", []() -> std::unique_ptr<JpgReaderFactory> {
      return std::make_unique<JpgReaderFactory>();
    });
  }

  ~ImageReaderCreator() {}

  std::unique_ptr<ImageReader> CreateReader(const std::string& filename) {
    std::string extension = GetExtension(filename);
    auto it = creators_.find(extension);
    if (it == creators_.end()) {
      throw std::runtime_error("Unsupported file format, extension: " +
                               extension);
    }
    return (it->second())->CreateReader();
  }

 private:
  void RegisterFactory(const std::string& type, Creator creator) {
    creators_[type] = std::move(creator);
  }

  std::string GetExtension(const std::string& filename) {
    auto pos = filename.find_last_of('.');
    if (pos == std::string::npos || pos == filename.length() - 1) {
      return "";
    }
    return filename.substr(pos + 1);
  }

  std::unordered_map<std::string, Creator> creators_;
};