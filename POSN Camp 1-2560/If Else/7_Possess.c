/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    double k,d,m,c,r,x,y;
    scanf("%lf %lf",&k,&d);
    m = (40-k)/15;
    r = sqrt(1+pow(m,2));
    x = 15+(d/r);
    y = 40+(d*m/r);
    while(x<0 || x>60 || y<0 || y>100){
        if(x<0)     x-=2*(x);
        if(x>60)    x-=2*(x-60);
        if(y<0)     y-=2*(y);
        if(y>100)   y-=2*(y-100);
    }
    printf("%.1lf %.1lf",x,y);
    return 0;
}
