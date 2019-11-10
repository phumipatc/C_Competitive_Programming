/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    if(a>79)        printf("A");
    else if(a>74)   printf("B+");
    else if(a>69)   printf("B");
    else if(a>64)   printf("C+");
    else if(a>59)   printf("C");
    else if(a>54)   printf("D+");
    else if(a>49)   printf("D");
    else            printf("F");
    return 0;
}
