// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_ITERATOR_OBJECT_LIST_OBJECT_LIST_H_
#define BEHAVIORAL_ITERATOR_OBJECT_LIST_OBJECT_LIST_H_

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

class IIterator {
 public:
  virtual ~IIterator() {}

  virtual void Next() = 0;
  virtual bool IsLast() const = 0;
  virtual std::string GetNextItem() = 0;

  virtual void Previous() = 0;
  virtual bool IsFirst() const = 0;
  virtual std::string GetPrevItem() = 0;
};

class ProductList;
class ProductIterator : public IIterator {
 public:
  ProductIterator(ProductList* list);

  virtual ~ProductIterator() {}

  void Next() override {
    if (forward_cursor_ < product_objects_.size()) {
      forward_cursor_++;
    }
  }

  bool IsLast() const override {
    return forward_cursor_ == product_objects_.size();
  }

  // Get the forward iterator item
  std::string GetNextItem() override {
    return product_objects_[forward_cursor_];
  }

  void Previous() override {
    if (reverse_cursor_ > -1) {
      reverse_cursor_--;
    }
  }

  bool IsFirst() const override { return reverse_cursor_ == -1; }

  // Get the previous iterator item
  std::string GetPrevItem() override {
    return product_objects_[reverse_cursor_];
  }

 private:
  std::vector<std::string> product_objects_;
  ProductList* product_list_;

  int forward_cursor_;
  int reverse_cursor_;
};

class ObjectList {
 public:
  ObjectList(const std::vector<std::string>& objects) : objects_(objects) {}
  virtual ~ObjectList() {}

  void Add(const std::string& obj) { objects_.emplace_back(obj); }
  void Remove(const std::string& obj) {
    objects_.erase(std::remove(objects_.begin(), objects_.end(), obj),
                   objects_.end());
  }

  std::vector<std::string> objects() const { return objects_; }

 private:
  std::vector<std::string> objects_;
};

class ProductList : public ObjectList {
 public:
  ProductList(const std::vector<std::string>& objects) : ObjectList(objects) {}

  std::shared_ptr<IIterator> CreateIterator() {
    return std::make_shared<ProductIterator>(this);
  }
};

inline ProductIterator::ProductIterator(ProductList* list)
    : product_list_(list) {
  product_objects_ = list->objects();
  forward_cursor_ = 0;
  reverse_cursor_ = product_objects_.size() - 1;
}

#endif  // BEHAVIORAL_ITERATOR_OBJECT_LIST_OBJECT_LIST_H_