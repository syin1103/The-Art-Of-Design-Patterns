// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <memory>

#include "file.h"

int main() {
  auto file1 = std::make_unique<ImageFile>("file1");
  auto file2 = std::make_unique<ImageFile>("file2");
  auto file3 = std::make_unique<TextFile>("file3");
  auto file4 = std::make_unique<TextFile>("file4");
  auto file5 = std::make_unique<VideoFile>("file5");

  auto folder1 = std::make_unique<Folder>("folder1");
  auto folder2 = std::make_unique<Folder>("folder2");
  auto folder3 = std::make_unique<Folder>("folder3");
  auto folder4 = std::make_unique<Folder>("folder4");

  folder2->Add(std::move(file1));
  folder2->Add(std::move(file2));
  folder3->Add(std::move(file3));
  folder3->Add(std::move(file4));
  folder4->Add(std::move(file5));
  folder1->Add(std::move(folder2));
  folder1->Add(std::move(folder3));
  folder1->Add(std::move(folder4));

  folder1->KillVirus();

  return 0;
}