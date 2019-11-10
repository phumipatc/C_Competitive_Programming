/*
    TASK:Intro04
    AUTHOR:Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    char x;
    scanf("%c",&x);
    printf("%c",(x==122)*(x-25)+(x!=122)*(x+1));
return 0;
}
