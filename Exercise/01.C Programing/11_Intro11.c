/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    double d,vr,vt,vf;
    scanf("%lf %lf %lf %lf",&d,&vr,&vt,&vf);
    printf("%.2lf",(d/(vt-vr))*vf);
return 0;
}
