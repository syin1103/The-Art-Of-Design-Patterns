// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_FACADE_BACKUP_BACKUP_H_
#define STRUCTURAL_FACADE_BACKUP_BACKUP_H_

#include <iostream>
#include <memory>

class IBackupItem {
 public:
  IBackupItem() = default;
  virtual ~IBackupItem() = default;

  virtual void Backup() = 0;
};

class ContactManager : public IBackupItem {
 public:
  ContactManager() = default;
  virtual ~ContactManager() = default;

  void Backup() override { std::cout << "Backup contact..." << std::endl; }
};

class SMSManager : public IBackupItem {
 public:
  SMSManager() = default;
  virtual ~SMSManager() = default;
  void Backup() override { std::cout << "Backup sms..." << std::endl; }
};

class PhotoManager : public IBackupItem {
 public:
  PhotoManager() = default;
  virtual ~PhotoManager() = default;
  void Backup() override { std::cout << "Backup photo..." << std::endl; }
};

#endif  // STRUCTURAL_FACADE_BACKUP_BACKUP_H_