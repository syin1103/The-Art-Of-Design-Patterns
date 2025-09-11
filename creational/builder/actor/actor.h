// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_BUILDER_ACTOR_ACTOR_H_
#define CREATIONAL_BUILDER_ACTOR_ACTOR_H_

#include <iostream>
#include <string>

class Actor {
 public:
  void set_type(const std::string& type) { type_ = type; }
  std::string type() const { return type_; }

  void set_sex(const std::string& sex) { sex_ = sex; }
  std::string sex() const { return sex_; }

  void set_face(const std::string& face) { face_ = face; }
  std::string face() const { return face_; }

  void set_custome(const std::string& custome) { custome_ = custome; }
  std::string custome() const { return custome_; }

  void set_hairstyle(const std::string& hairstyle) { hairstyle_ = hairstyle; }
  std::string hairstyle() const { return hairstyle_; }

  void Display() {
    std::cout << type() << ", " << sex() << ", " << face() << ", " << custome()
              << ", " << hairstyle() << std::endl;
  }

 private:
  std::string type_;
  std::string sex_;
  std::string face_;
  std::string custome_;
  std::string hairstyle_;
};

#endif  // CREATIONAL_BUILDER_ACTOR_ACTOR_H_