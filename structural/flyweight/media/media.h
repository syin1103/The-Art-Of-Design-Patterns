// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_FLYWIGHT_MEDIA_MEDIA_H_
#define STRUCTURAL_FLYWIGHT_MEDIA_MEDIA_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Position {
  int x;
  int y;
  int width;
  int height;
};

class Media {
 public:
  Media(const std::string& content) : content_(content) {}
  virtual ~Media() = default;
  virtual void Display(const Position& pos) const = 0;

 protected:
  std::string content_;
};

class Image : public Media {
 public:
  Image(const std::string& content) : Media(content) {}
  virtual ~Image() = default;

  void Display(const Position& pos) const override {
    std::cout << "Image: " << content_ << ", Position: " << pos.x << ", "
              << pos.y << ", " << pos.width << ", " << pos.height << std::endl;
  }
};

class Animation : public Media {
 public:
  Animation(const std::string& content) : Media(content) {}
  virtual ~Animation() = default;

  void Display(const Position& pos) const override {
    std::cout << "Animation: " << content_ << ", Position: " << pos.x << ", "
              << pos.y << ", " << pos.width << ", " << pos.height << std::endl;
  }
};

class Video : public Media {
 public:
  Video(const std::string& content) : Media(content) {}
  virtual ~Video() = default;

  void Display(const Position& pos) const override {
    std::cout << "Video: " << content_ << ", Position: " << pos.x << ", "
              << pos.y << ", " << pos.width << ", " << pos.height << std::endl;
  }
};

class MediaReference {
 public:
  MediaReference(std::shared_ptr<Media> media, const Position& pos)
      : media_(media), pos_(pos) {}

  void Display() const { media_->Display(pos_); }
  void set_position(const Position& pos) { pos_ = pos; }

 private:
  Position pos_;
  std::shared_ptr<Media> media_;
};

#endif  // STRUCTURAL_FLYWIGHT_MEDIA_MEDIA_H_