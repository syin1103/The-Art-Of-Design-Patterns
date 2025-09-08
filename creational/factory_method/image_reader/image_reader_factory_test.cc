// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <iostream>

#include "image_reader.h"
#include "image_reader_creator.h"

int main() {
  ImageReaderCreator creator;

  creator.CreateReader("test0.jpg");
  creator.CreateReader("test1.png");
  creator.CreateReader("test2.gif");
  return 0;
}