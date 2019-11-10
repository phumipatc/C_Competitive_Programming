/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
double a[];
double b[1200];
int main()
{
    int i;
    scanf(" %s %s",a,b);
    for(i=0;i<b;i++)
    a=(a*b);
    printf("%s",a);
return 0;
}
