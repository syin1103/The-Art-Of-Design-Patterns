// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_COMPOSITE_VIRUS_FILE_H_
#define STRUCTURAL_COMPOSITE_VIRUS_FILE_H_

#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

class AbstractFile {
 public:
  virtual void Add(std::unique_ptr<AbstractFile> file) {
    throw std::runtime_error("Unsupport operation.");
  }

  virtual void Remove(AbstractFile* file) {
    throw std::runtime_error("Unsupport operation.");
  }

  virtual AbstractFile* GetChild(int i) {
    throw std::runtime_error("Unsupport operation.");
  }

  virtual void KillVirus() = 0;
};

class ImageFile : public AbstractFile {
 public:
  ImageFile(const std::string& name) : name_(name) {}
  void KillVirus() override {
    std::cout << "ImageFile: kill virus: " << name_ << std::endl;
  }

 private:
  std::string name_;
};

class TextFile : public AbstractFile {
 public:
  TextFile(const std::string& name) : name_(name) {}
  void KillVirus() override {
    std::cout << "TextFile: kill virus: " << name_ << std::endl;
  }

 private:
  std::string name_;
};

class VideoFile : public AbstractFile {
 public:
  VideoFile(const std::string& name) : name_(name) {}
  void KillVirus() override {
    std::cout << "VideoFile: kill virus: " << name_ << std::endl;
  }

 private:
  std::string name_;
};

class Folder : public AbstractFile {
 public:
  Folder(const std::string& name) : name_(name) {}
  void Add(std::unique_ptr<AbstractFile> file) override {
    children.emplace_back(std::move(file));
  }

  void Remove(AbstractFile* file) override {
    for (auto it = children.begin(); it != children.end(); it++) {
      if ((*it).get() == file) {
        children.erase(it);
        break;
      }
    }
  }

  AbstractFile* GetChild(int i) override {
    if (i < children.size()) {
      return children[i].get();
    }
    return nullptr;
  }

  void KillVirus() override {
    for (const auto& child : children) {
      child->KillVirus();
    }
  }

 private:
  std::string name_;
  std::vector<std::unique_ptr<AbstractFile>> children{};
};

#endif  // STRUCTURAL_COMPOSITE_VIRUS_FILE_H_