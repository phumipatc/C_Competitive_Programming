/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
double pow(double a,double b){
    if(b==0){
        return 1;
    }else{
        return a * pow(a,b-1);
    }
}
int main()
{
    double a,b,x;
    scanf("%lf %lf",&a,&b);
    x=pow(a,b);
    printf("%.2lf",x);
return 0;
}
