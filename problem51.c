#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int index=1;
  char *user_string=(char*)calloc(100,sizeof(char));
  char single_char;
  printf("enter the user string: ");
  scanf("%100[^\n]",user_string); 
  getchar();
  printf("enter the single char: ");
  scanf("%c",&single_char);
  while(*user_string!='\0')
  {
    if (*user_string==single_char)
    {
        printf("%d ",index);
    }
    index++;
    user_string++;
  }
  
  free(user_string);
  user_string=NULL;
    return 0;
}