// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_FACTORY_METHOD_IMAGE_READER_IMAGE_READER_H_
#define CREATIONAL_FACTORY_METHOD_IMAGE_READER_IMAGE_READER_H_

#include <iostream>

class ImageReader {};

class GifReader : public ImageReader {
 public:
  GifReader() { std::cout << "Gif Reader ..." << std::endl; }
  ~GifReader() {}
};

class PngReader : public ImageReader {
 public:
  PngReader() { std::cout << "Png Reader ..." << std::endl; }
  ~PngReader() {}
};

class JpgReader : public ImageReader {
 public:
  JpgReader() { std::cout << "Jpg Reader ..." << std::endl; }
  ~JpgReader() {}
};

#endif  // CREATIONAL_FACTORY_METHOD_IMAGE_READER_IMAGE_READER_H_