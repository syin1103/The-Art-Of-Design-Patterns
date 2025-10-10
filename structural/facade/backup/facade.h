// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_FACADE_BACKUP_FACADE_H_
#define STRUCTURAL_FACADE_BACKUP_FACADE_H_

#include <memory>
#include <vector>

#include "backup.h"

class BackupFacade {
 public:
  BackupFacade() {
    Register(std::make_unique<ContactManager>());
    Register(std::make_unique<SMSManager>());
    Register(std::make_unique<PhotoManager>());
  }

  void Backup() {
    for (const auto& item : backup_) {
      item->Backup();
    }
  }

 private:
  void Register(std::unique_ptr<IBackupItem> item) {
    backup_.emplace_back(std::move(item));
  }

  std::vector<std::unique_ptr<IBackupItem>> backup_;
};

#endif  // STRUCTURAL_FACADE_BACKUP_FACADE_H_