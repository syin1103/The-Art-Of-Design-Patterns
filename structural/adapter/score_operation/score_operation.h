// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_ADAPTER_SCORE_OPERATION_SCORE_OPERATION_H_
#define STRUCTURAL_ADAPTER_SCORE_OPERATION_SCORE_OPERATION_H_

#include <memory>
#include <vector>

#include "algo.h"

class ScoreOperation {
 public:
  virtual std::vector<int> Sort(const std::vector<int>& array) = 0;
  virtual int Search(const std::vector<int>& array, int key) = 0;
};

class OperationAdapter : public ScoreOperation {
 public:
  std::vector<int> Sort(const std::vector<int>& array) override {
    std::vector<int> res = array;
    quick_sort_.Sort(res);
    return res;
  }

  int Search(const std::vector<int>& array, int key) override {
    return binary_search_.Search(array, key);
  }

 private:
  QuickSort quick_sort_;
  BinarySearch binary_search_;
};

#endif  // STRUCTURAL_ADAPTER_SCORE_OPERATION_SCORE_OPERATION_H_