#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{char *main_string=(char*)calloc(100,sizeof(char));
 char *sub_string=(char*)calloc(99,sizeof(char));
 printf("enter the main string: ");
 scanf("%100[^\n]",main_string);
 getchar();
 printf("enter the sub_string: ");
 scanf("%99[^\n]",sub_string);
 char* data=strstr(main_string,sub_string);
 if (data!=NULL)
 printf("%d",1+data-main_string);
 else 
 printf("No sub_string press in main_string as %s",sub_string);
free(main_string);
free(sub_string);
main_string=NULL;
sub_string=NULL;
    return 0;
}