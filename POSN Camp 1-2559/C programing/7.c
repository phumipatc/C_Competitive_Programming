/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    printf("%d %d",(((x/8)%8)%2==0)*(x%8)+(((x/8)%8)%2==1)*(7-(x%8)),(x/8)%8);
return 0;
}
