// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_BRIDGE_IMAGE_IMAGE_H_
#define STRUCTURAL_BRIDGE_IMAGE_IMAGE_H_

#include <iostream>
#include <memory>
#include <string>

#include "image_impl.h"

class Image {
 public:
  void set_image_impl(std::unique_ptr<ImageImpl> impl) {
    image_impl_ = std::move(impl);
  }

  virtual void ParseFile(const std::string& filename) = 0;

 protected:
  std::unique_ptr<ImageImpl> image_impl_ = nullptr;
};

class JPGImage : public Image {
 public:
  void ParseFile(const std::string& filename) override {
    std::cout << "JPGImage, ";
    image_impl_->DoPaint(Matrix(filename));
  }
};

class PNGImage : public Image {
 public:
  void ParseFile(const std::string& filename) override {
    std::cout << "PNGImage, ";
    image_impl_->DoPaint(Matrix(filename));
  }
};

class BMPImage : public Image {
 public:
  void ParseFile(const std::string& filename) override {
    std::cout << "BMPImage, ";
    image_impl_->DoPaint(Matrix(filename));
  }
};

#endif  // STRUCTURAL_BRIDGE_IMAGE_IMAGE_H_