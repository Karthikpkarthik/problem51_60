#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_DIGITS 50
/// @brief reverse string
/// @param data 
void reverse(char data[]);
/// @brief separate operaters in input field
/// @param input 
/// @param operand1 
/// @param operand2 
/// @param operation 
void slice(char input[], char operand1[], char operand2[], char *operation);
/// @brief check the operand for any invalid things 
/// @param operand1 
/// @param operand2 
/// @return 
bool num_check(char operand1[], char operand2[]);
/// @brief subtraction between operand1 and operand2
/// @param num1 
/// @param num2 
/// @param result 
void sub(char num1[], char num2[], char result[]);
/// @brief addition between operand1 and operand2
/// @param num1 
/// @param num2 
/// @param result 
void add(char num1[], char num2[], char result[]);
/// @brief multiplication between operand1 and operand2
/// @param string1 
/// @param string2 
/// @param result 
void mult(char string1[], char string2[], char result[]);
/// @brief division between operand1 and operand2
/// @param dividend 
/// @param div 
void divide(char dividend[], char div[]);