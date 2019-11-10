/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    char str[10]="ABC";
    char *ptr;
    ptr = str;
    for(;*ptr;ptr++)
    printf("%c\t",*ptr);
return 0;
}
