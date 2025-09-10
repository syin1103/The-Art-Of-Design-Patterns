// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_PROTOTYPE_OFFICIAL_DOCUMENT_H_
#define CREATIONAL_PROTOTYPE_OFFICIAL_DOCUMENT_H_

#include <iostream>
#include <memory>

class OfficialDocument {
 public:
  OfficialDocument() = default;
  virtual ~OfficialDocument() = default;

  virtual std::unique_ptr<OfficialDocument> Clone() const = 0;
  virtual void Display() const = 0;
};

class FARDocument : public OfficialDocument {
 public:
  FARDocument() = default;
  virtual ~FARDocument() = default;

  std::unique_ptr<OfficialDocument> Clone() const override {
    return std::make_unique<FARDocument>();
  }

  std::unique_ptr<FARDocument> CloneFAR() const {
    return std::make_unique<FARDocument>();
  }

  void Display() const override {
    std::cout << "FARDocument Display..." << std::endl;
  }
};

class SRSDocument : public OfficialDocument {
 public:
  SRSDocument() = default;
  virtual ~SRSDocument() = default;

  std::unique_ptr<OfficialDocument> Clone() const override {
    return std::make_unique<SRSDocument>();
  }

  std::unique_ptr<SRSDocument> CloneSRS() const {
    return std::make_unique<SRSDocument>();
  }

  void Display() const override {
    std::cout << "SRSDocument Display..." << std::endl;
  }
};

#endif  // CREATIONAL_PROTOTYPE_OFFICIAL_DOCUMENT_H_