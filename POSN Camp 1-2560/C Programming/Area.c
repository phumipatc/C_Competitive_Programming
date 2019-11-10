/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<math.h>
int main(){
    double a;
    scanf("%lf",&a);
    printf("Area of shape1 = %lf\n",((M_PI)*(a/2)*(a/2))/2);
    printf("Area of shape2 = %lf\n",a*a*2);
    printf("Area of shape3 = %lf\n",(a+3)*a/2);
    printf("Area of this shape = %lf\n",(((M_PI)*(a/2)*(a/2))/2)+(a*a*2)+((a+3)*a/2));
    return 0;
}
