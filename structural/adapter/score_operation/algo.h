// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef STRUCTURAL_ADAPTER_SCORE_OPERATION_ALGL_H_
#define STRUCTURAL_ADAPTER_SCORE_OPERATION_ALGL_H_

#include <algorithm>
#include <vector>

class QuickSort {
 public:
  void Sort(std::vector<int>& array) { std::sort(array.begin(), array.end()); }
};

class BinarySearch {
 public:
  bool Search(const std::vector<int>& array, int key) {
    return std::binary_search(array.begin(), array.end(), key);
  }
};

#endif  // STRUCTURAL_ADAPTER_SCORE_OPERATION_ALGL_H_