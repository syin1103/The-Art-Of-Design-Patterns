// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "context.h"
#include "node.h"
int main() {
  std::string text1 =
      "LOOP 2 PRINT Yangguo SPACE SPACE PRINT XiaoLongnv BREAK END PRINT "
      "Guojing SPACE SPACE PRINT Huangrong";

  std::string text2 =
      "LOOP 2 LOOP 2 PRINT Jack SPACE SPACE PRINT Lucy BREAK END PRINT Mike "
      "SPACE SPACE PRINT Meimei BREAK END";

  Context ctx1(text1);
  Context ctx2(text2);

  ExpressionCommandNode expression1;
  expression1.Interpret(ctx1);
  expression1.Execute();

  std::cout << "\n--------------" << std::endl;

  ExpressionCommandNode expression2;
  expression2.Interpret(ctx2);
  expression2.Execute();

  return 0;
}