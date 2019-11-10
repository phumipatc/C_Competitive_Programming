/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<math.h>
int main()
{
    double x1,x2,x3,y1,y2,y3,s,a,b,c,k;
    scanf("%lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&k);
    a=sqrt((pow(x2-x1,2)+pow(y2-y1,2)));
    b=sqrt((pow(x3-x2,2)+pow(y3-y2,2)));
    c=sqrt((pow(x1-x3,2)+pow(y1-y3,2)));
    s=(a+b+c)/2;
    printf("%.2lf\n",sqrt(s*(s-a)*(s-b)*(s-c)));
    printf("%.2lf\n",((M_PI)*k*k)+((a+b+c)*k));
    return 0;
}
