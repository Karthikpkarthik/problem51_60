#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ecen/local_math_lib.h"
int main()
{
  while (true)
  {
    char input[200];
    char operand1[MAX_DIGITS + 1] = {0}, operand2[MAX_DIGITS + 1] = {0}, result[MAX_DIGITS * 2 + 1] = {0};
    char operation;
    bool valid_input;

    printf("Calu>");
    fgets(input, sizeof(input), stdin);
    if (strcmp(input, "exit") || strcmp(input, "Exit"))
      return 0;
    slice(input, operand1, operand2, &operation);
    if (num_check(operand1, operand2))
    {
      switch (operation)
      {
      case '+':
        add(operand1, operand2, result);
        break;
      case '-':
        sub(operand1, operand2, result);
        break;
      case '*':
        mult(operand1, operand2, result);
        break;
      case '/':
        divide(operand1, operand2);
        break;
      }
    }
    else
      printf("invalid operands\n");
  }
  return 0;
}