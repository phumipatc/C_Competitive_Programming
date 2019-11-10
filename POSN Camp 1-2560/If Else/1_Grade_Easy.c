/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n>79)        printf("A");
    else if(n>74)   printf("B+");
    else if(n>69)   printf("B");
    else if(n>64)   printf("C+");
    else if(n>59)   printf("C");
    else if(n>54)   printf("D+");
    else if(n>49)   printf("D");
    else            printf("F");
    return 0;
}
