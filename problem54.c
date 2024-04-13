#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char data[])
{int size=strlen(data);
  for (int i = 0; i < size/ 2; i++)
  {
    char temp = data[i];
    data[i] = data[size - i - 1];
    data[size - i - 1] = temp;
  }
}
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

}
int main()
{
  char *string1 = (char *)calloc(100, sizeof(char));
  char *string2 = (char *)calloc(100, sizeof(char));
  scanf("%100[^\n]", string1);
  getchar();
  scanf("%100[^\n]", string2);
  int size_num1 = strlen(string1);
  int size_num2 = strlen(string2);
  int total = size_num1 + size_num2;
  char result[total];
  for (int i = 0; i < size_num1 + size_num2; i++)
    result[i] = 0;
  mult(string1,string2,result);
  for (int i = 0; i < strlen(result); i++)
    printf("%u", result[i]);
  printf("\n");
  free(string1);
  free(string2);
  string1 = NULL;
  string2 = NULL;
  return 0;
}