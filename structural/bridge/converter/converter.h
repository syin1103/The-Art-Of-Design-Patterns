// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_BRIDGE_CONVERTER_CONVERTER_H_
#define STRUCTURAL_BRIDGE_CONVERTER_CONVERTER_H_

#include <cassert>
#include <memory>
#include <string>

#include "database.h"

class FileConverter {
 public:
  FileConverter(std::unique_ptr<Database> db, const std::string& filename)
      : db_(std::move(db)), output_(filename) {}
  virtual ~FileConverter() {}

  void ConvertData(const std::string& query) {
    assert(db_ != nullptr);
    db_->Connect("Kylin");
    auto data = db_->ExcuteQuery(query);
    Convert(data);
    db_->Disconnect();
  }

  virtual void Convert(const std::string& data) = 0;

  void set_database(std::unique_ptr<Database> db) { db_ = std::move(db); }

 private:
  std::string output_{};
  std::unique_ptr<Database> db_ = nullptr;
};

class TXTConverter : public FileConverter {
 public:
  TXTConverter(std::unique_ptr<Database> db, const std::string& filename)
      : FileConverter(std::move(db), filename + ".txt") {}

  void Convert(const std::string& data) override {
    std::cout << "TXTConverter: " << data << std::endl;
  }
};

class PDFConverter : public FileConverter {
 public:
  PDFConverter(std::unique_ptr<Database> db, const std::string& filename)
      : FileConverter(std::move(db), filename + ".pdf") {}

  void Convert(const std::string& data) override {
    std::cout << "PDFConverter: " << data << std::endl;
  }
};

class XMLConverter : public FileConverter {
 public:
  XMLConverter(std::unique_ptr<Database> db, const std::string& filename)
      : FileConverter(std::move(db), filename + ".xml") {}

  void Convert(const std::string& data) override {
    std::cout << "XMLConverter: " << data << std::endl;
  }
};

class ConverterFactory {
 public:
  static std::unique_ptr<FileConverter> CreateConverter(
      const std::string& type, std::unique_ptr<Database> db,
      const std::string& filename) {
    if (type == "TXT") {
      return std::make_unique<TXTConverter>(std::move(db), filename);
    } else if (type == "PDF") {
      return std::make_unique<PDFConverter>(std::move(db), filename);
    } else if (type == "XML") {
      return std::make_unique<XMLConverter>(std::move(db), filename);
    }
    return nullptr;
  }
};

#endif  // STRUCTURAL_BRIDGE_CONVERTER_CONVERTER_H_