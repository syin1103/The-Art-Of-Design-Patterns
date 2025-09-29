// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <memory>
#include <string>

#include "control.h"

int main() {
  auto button1 = std::make_shared<Button>("确定按钮");
  auto button2 = std::make_shared<Button>("取消按钮");
  auto textBox = std::make_shared<TextBox>("用户名输入框");

  auto panel = std::make_shared<Panel>("主面板");
  panel->Add(button1);
  panel->Add(button2);

  auto window = std::make_shared<Window>("主窗口");
  window->Add(panel);
  window->Add(textBox);

  window->Draw();
  panel->Draw();

  panel->Remove(button1);
  panel->Draw();

  return 0;
}