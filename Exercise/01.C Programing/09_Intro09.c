/*
    TASK:Intro09
    AUTHOR:Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int x,y,m,e,f;
    int a1,a2,a3,a4,b1,b2,b3,b4,c1,c2,c3,c4,c5;
    scanf("%d %d",&e,&f);

    a4=e%10;e=e/10;
    a3=e%10;e=e/10;
    a2=e%10;e=e/10;
    a1=e%10;e=e/10;

    b4=f%10;f=f/10;
    b3=f%10;f=f/10;
    b2=f%10;f=f/10;
    b1=f%10;f=f/10;

    x=(a1*8)+(a2*4)+(a3*2)+a4;
    y=(b1*8)+(b2*4)+(b3*2)+b4;
    m=x+y;

    c5=m%2;m=m/2;
    c4=m%2;m=m/2;
    c3=m%2;m=m/2;
    c2=m%2;m=m/2;
    c1=m%2;m=m/2;

    printf("%d%d%d%d%d",c1,c2,c3,c4,c5);
return 0;
}
