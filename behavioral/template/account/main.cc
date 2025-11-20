// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "account.h"

int main() {
  CurrAccount curr;
  curr.Handle("ZhangWuji", "123");
  curr.Handle("ZhangWuji", "123456");

  SaveAccount save;
  save.Handle("ZhangWuji", "123");
  save.Handle("ZhangWuji", "123456");

  return 0;
}