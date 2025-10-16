// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <string>

#include "document.h"
#include "media.h"
#include "media_factory.h"

int main() {
  Document doc;

  doc.InsertMedia("image", "sunset.jpg", {100, 100, 200, 150});
  doc.InsertMedia("image", "sunset.jpg", {400, 300, 100, 75});

  doc.InsertMedia("animation", "intro.anim", {50, 50, 300, 200});
  doc.InsertMedia("animation", "intro.anim", {200, 150, 150, 100});

  doc.InsertMedia("video", "demo.mp4", {0, 0, 640, 480});

  doc.DisplayAll();

  return 0;
}