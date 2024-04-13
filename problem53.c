#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{    unsigned int words_count=1;
    char *user_string=(char*)calloc(100,sizeof(char));
    printf("string: ");
    gets(user_string);
    while (*user_string!='\0')
    {
        if (*user_string==' ')
        words_count+=1;
        user_string++;
    }
    printf("%d",words_count);
    return 0;
}