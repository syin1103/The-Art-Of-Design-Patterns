// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_BUILDER_ACTOR_ACTOR_BUILDER_H_
#define CREATIONAL_BUILDER_ACTOR_ACTOR_BUILDER_H_

#include "actor.h"

class ActorBuilder {
 public:
  virtual ~ActorBuilder() = default;

  virtual void BuildType() = 0;
  virtual void BuildSex() = 0;
  virtual void BuildFace() = 0;
  virtual void BuildCustome() = 0;
  virtual void BuildHairstyle() = 0;

  virtual bool IsBaldHead() const { return false; }

  Actor CreateActor() { return actor_; }

 protected:
  Actor actor_;
};

class HeroBuilder : public ActorBuilder {
 public:
  void BuildType() override { actor_.set_type("hero"); }
  void BuildSex() override { actor_.set_sex("male"); }
  void BuildFace() override { actor_.set_face("handsome"); }
  void BuildCustome() override { actor_.set_custome("armor"); }
  void BuildHairstyle() override { actor_.set_hairstyle("elegant"); }
};

class AngelBuilder : public ActorBuilder {
 public:
  void BuildType() override { actor_.set_type("angel"); }
  void BuildSex() override { actor_.set_sex("female"); }
  void BuildFace() override { actor_.set_face("beautiful"); }
  void BuildCustome() override { actor_.set_custome("white dress"); }
  void BuildHairstyle() override { actor_.set_hairstyle("long hair"); }
};

class DevilBuilder : public ActorBuilder {
  void BuildType() override { actor_.set_type("devil"); }
  void BuildSex() override { actor_.set_sex("demon"); }
  void BuildFace() override { actor_.set_face("ugly"); }
  void BuildCustome() override { actor_.set_custome("black clothes"); }
  void BuildHairstyle() override { actor_.set_hairstyle("bald head"); }
  bool IsBaldHead() const override { return true; }
};

#endif  // CREATIONAL_BUILDER_ACTOR_ACTOR_BUILDER_H_