#include"local_math_lib.h"
/// @brief reverse string
/// @param data 
void reverse(char data[])
{
  int size = strlen(data);
  for (int i = 0; i < size / 2; i++)
  {
    char temp = data[i];
    data[i] = data[size - i - 1];
    data[size - i - 1] = temp;
  }
}
/// @brief separate operaters in input field
/// @param input 
/// @param operand1 
/// @param operand2 
/// @param operation 
void slice(char input[], char operand1[], char operand2[], char *operation)
{
  bool oper1_flag = true;
  bool oper2_flag = false;
  bool first = true;
  bool second = false;
  int index = 0;
  for (int i = 0; i < strlen(input); i++)
  {
    if ((input[i] == '*' || input[i] == '-' || input[i] == '+' || input[i] == '/') && first)
    {
      *operation = input[i];
      oper2_flag = true;
      oper1_flag = false;
      index = 0;
      first = false;
      second = true;
      i += 1;
    }
    if (oper1_flag)
      operand1[index++] = input[i];
    if (second && (input[i] == '-'))
      break;
    if (oper2_flag)
      operand2[index++] = input[i];
  }
}
/// @brief  check the operand for any invalid things 
/// @param operand1 
/// @param operand2 
/// @return 
bool num_check(char operand1[], char operand2[])
{
  bool valid = true;
  if (operand1 == "exit" && operand1 == "Exit")
    exit(1);
  for (int i = 0; i < strlen(operand1); i++)
    if (operand1[i] < '0' || operand1[i] > '9')
      valid = false;
  for (int i = 0; i < strlen(operand2); i++)
    if (operand2[i] < '0' || operand2[i] > '9')
      valid = false;
  return valid;
}
/// @brief subtraction between operand1 and operand2
/// @param num1 
/// @param num2 
/// @param result 
void sub(char num1[], char num2[], char result[])
{
  bool negative = false;
  char symbal = '-';
  if (strlen(num1) == strlen(num2))
  {
    for (int i = 0; i < strlen(num1); i++)
    {
      if (num1[i] < num2[i])
      {
        negative = true;
        break;
      }
    }
  }

  if (negative || strlen(num1) < strlen(num2))
  {
    negative = true;
    char *temp = (char *)calloc(51, sizeof(char));
    strcpy(temp, num1);
    strcpy(num1, num2);
    strcpy(num2, temp);
  }

  reverse(num1);
  reverse(num2);
  char *firstp = result;
  char rem = 0, large_num = 0, small_num = 0;
  if (strlen(num1) < strlen(num2))
  {
    large_num = strlen(num2);
    small_num = strlen(num1);
  }
  else
  {
    large_num = strlen(num1);
    small_num = strlen(num2);
  }
  for (int i = 0; i < small_num; i++)
  {
    int count = 0;
    if (*num1 < *num2)
    {
      num1++;
      while (*num1 == '0')
      {
        count++;
        num1++;
      }
      *num1 = *num1 - 1;
      for (int j = 0; j < count; j++)
      {
        num1--;
        *num1 = '9';
      }
      num1--;
      char temp = (*num1 - '0') + 10;
      *result = (temp - (*num2 - '0')) + '0';
      result++;
    }
    else
    {
      *result = ((*num1 - '0') - (*num2 - '0')) + '0';
      result++, num1++, num2++;
    }
  }
  if (strlen(num1) > strlen(num2))
  {
    num1 = num1 + (strlen(num2));
    while (*num1 != '\0')
    {
      *result = *num1;
      result++, num1++;
    }
  }
  if (strlen(num2) < strlen(num1))
  {
    num2 = num2 + (strlen(num1));
    while (*num2 != '\0')
    {

      *result = *num2;
      result++, num2++;
    }
  }
  if (negative)
  {
    *result = '-';
  }
  result = firstp;

  reverse(result);
  printf("%s\n", result);
}
/// @brief addition between operand1 and operand2
/// @param num1 
/// @param num2 
/// @param result 
void add(char num1[], char num2[], char result[])
{
  reverse(num1);
  reverse(num2);
  char *t = result;
  char rem = 0, large_num = 0, small_num = 0;
  if (strlen(num1) < strlen(num2))
  {
    large_num = strlen(num2);
    small_num = strlen(num1);
  }
  else
  {
    large_num = strlen(num1);
    small_num = strlen(num2);
  }

  for (int i = 0; i < small_num; i++)
  {
    char temp = (*num1 - '0') + (*num2 - '0');

    temp += rem;
    rem = temp / 10;
    *result = (temp % 10) + '0';

    num1++, num2++, result++;
  }

  if (rem != 0 || strlen(num1) != 0 || strlen(num2) != 0)
  {
    if (strlen(num1) != 0)
    {
      while (*num1 != '\0')
      {
        char temp = (*num1 - '0') + rem;

        rem = temp / 10;
        *result = (temp % 10) + '0';
        result++, num1++;
      }
    }
    if (strlen(num2) != 0)
    {
      while (*num2 != '\0')
      {
        char temp = (*num2 - '0') + rem;
        rem = temp / 10;
        *result = (temp % 10) + '0';

        result++, num2++;
      }
    }
  }
  result = t;
  reverse(result);
  printf("%s\n", result);
}
/// @brief  multiplication between operand1 and operand2
/// @param string1 
/// @param string2 
/// @param result 
void mult(char string1[], char string2[], char result[])
{
  char num1[50] = {0};
  char num2[50] = {0};
  for (int i = 0; i < strlen(string1); i++)
    num1[i] = string1[i] - '0';
  for (int i = 0; i < strlen(string2); i++)
    num2[i] = string2[i] - '0';
  int size_num1 = strlen(string1);
  int size_num2 = strlen(string2);
  int total = size_num1 + size_num2;
  int inc = 0;
  reverse(num1);
  reverse(num2);
  for (int i = 0; i < size_num1; i++)
  {
    int rem = 0;
    int num_1 = num1[i];
    char data[size_num2 + 1];
    for (int j = 0; j < size_num2; j++)
    {
      char temp = num2[j] * num_1;
      temp += rem;
      rem = temp / 10;
      temp = temp % 10;
      data[j] = temp;
    }
    int set = 0;
    for (int j = 0; j < size_num2; j++)
    {
      int temp = result[j + inc] + data[j];
      temp += set;
      set = temp / 10;
      result[j + inc] = temp % 10;
    }
    inc++;
  }
  reverse(result);
  for (int i = 0; i < strlen(result); i++)
    printf("%u", result[i]);
  printf("\n");
}
/// @brief division between operand1 and operand2
/// @param dividend 
/// @param div 
void divide(char dividend[], char div[])
{
  char quotient[MAX_DIGITS] = {0};
  int remainder = 0;
  int quotientIndex = 0;
  int divisor = atoi(div);
  for (int i = 0; i < strlen(dividend); i++)
  {
    int digit = dividend[i] - '0';
    remainder = remainder * 10 + digit;
    quotient[quotientIndex++] = remainder / divisor + '0';
    remainder = remainder % divisor;
  }

  reverse(quotient);
  // Check for leading zeros in quotient
  int start = strlen(quotient);
  for (int i = start - 1; i >= 0; i--)
  {
    if (quotient[i] == '0')
    {
      quotient[i] = '\0';
    }
    else
      break;
  }
  reverse(quotient);
  // Print quotient
  printf("Quotient: %s\n", quotient);
  printf("Remainder: %d\n", remainder);
}