/*
    TASK:Intro08
    AUTHOR:Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d %d",(((n/8)%8)%2==0)*(n%8)+(((n/8)%8)%2==1)*(7-(n%8)),(n/8)%8);
return 0;
}
