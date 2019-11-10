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
    double a,b;
    scanf("%lf %lf",&a,&b);
    printf("Plus: %.2lf\n",a+b);
    printf("Minus: %.2lf\n",a-b);
    printf("Multiply: %.2lf\n",a*b);
    printf("Divide: %.2lf\n",a/b);
    printf("Modulo: %.2lf\n",fmod(a,b));
    printf("Power: %.2lf\n",pow(a,b));
    printf("Root: %.2lf\n",pow(a,1/b));
return 0;
}
