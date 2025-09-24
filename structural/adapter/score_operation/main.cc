// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <iostream>
#include <vector>

#include "score_operation.h"

int main() {
  std::vector<int> array{10, 9, 20, 28, 6, 16};

  std::vector<int> res = OperationAdapter().Sort(array);
  std::for_each(res.begin(), res.end(),
                [](int x) { std::cout << x << std::endl; });

  bool flag = OperationAdapter().Search(array, 20);
  std::cout << flag << std::endl;

  return 0;
}