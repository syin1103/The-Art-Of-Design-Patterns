// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "image.h"
#include "image_factory.h"
#include "image_impl.h"

int main() {
  auto png = ImageFactory::CreateImage("PNG");
  png->set_image_impl(std::make_unique<LinuxImpl>());
  png->ParseFile("test.png");

  auto jpg = ImageFactory::CreateImage("JPG");
  jpg->set_image_impl(std::make_unique<WindowsImpl>());
  jpg->ParseFile("test.jpg");

  auto bmp = ImageFactory::CreateImage("BMP");
  bmp->set_image_impl(std::make_unique<UnixImpl>());
  bmp->ParseFile("test.bmp");
}