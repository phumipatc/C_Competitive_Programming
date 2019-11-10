/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<math.h>
int main()
{
    double X1,Y1,X2,Y2,X3,Y3,K,a,b,c,d;
    scanf("%lf %lf %lf %lf %lf %lf %lf",&X1,&Y1,&X2,&Y2,&X3,&Y3,&K);
    a=sqrt(pow(X1-X2,2)+pow(Y1-Y2,2));
    b=sqrt(pow(X2-X3,2)+pow(Y2-Y3,2));
    c=sqrt(pow(X3-X1,2)+pow(Y3-Y1,2));
    d=(a+b+c)/2;

    printf("%.2lf\n%.2lf",sqrt(d*(d-a)*(d-b)*(d-c)),((M_PI)*K*K)+((a+b+c)*K));
return 0;
}
