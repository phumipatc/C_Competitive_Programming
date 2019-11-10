/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int x,y,sum,z1,z2,z3,z4,z5;
    char a1,a2,a3,a4,b1,b2,b3,b4;
    scanf(" %c %c %c %c %c %c %c %c",&a1,&a2,&a3,&a4,&b1,&b2,&b3,&b4);
    x=(a1*8)+(a2*4)+(a3*2)+a4;
    y=(b1*8)+(b2*4)+(b3*2)+b4;
    sum=x+y;
    z5=sum%2; sum=sum/2;
    z4=sum%2; sum=sum/2;
    z3=sum%2; sum=sum/2;
    z2=sum%2; sum=sum/2;
    z1=sum%2; sum=sum/2;
    printf("%d%d%d%d%d",z1,z2,z3,z4,z5);
    return 0;
}
