// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_BRIDGE_IMAGE_IMAGE_IMPL_H_
#define STRUCTURAL_BRIDGE_IMAGE_IMAGE_IMPL_H_

#include <iostream>
#include <string>

struct Matrix {
  Matrix(const std::string& filename) : name(filename) {}
  std::string name;
};

class ImageImpl {
 public:
  virtual void DoPaint(Matrix m) = 0;
};

class WindowsImpl : public ImageImpl {
 public:
  void DoPaint(Matrix m) override {
    std::cout << "windows: " << m.name << std::endl;
  }
};

class LinuxImpl : public ImageImpl {
 public:
  void DoPaint(Matrix m) override {
    std::cout << "linux: " << m.name << std::endl;
  }
};

class UnixImpl : public ImageImpl {
 public:
  void DoPaint(Matrix m) override {
    std::cout << "unix: " << m.name << std::endl;
  }
};

#endif  // STRUCTURAL_BRIDGE_IMAGE_IMAGE_IMPL_H_