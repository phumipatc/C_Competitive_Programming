/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<math.h>
int main()
{
    double A,B;
    scanf("%lf %lf",&A,&B);
    printf("Plus: %.2lf\n",A+B);
    printf("Minus: %.2lf\n",A-B);
    printf("Multiply: %.2lf\n",A*B);
    printf("Divide: %.2lf\n",A/B);
    printf("Modulo: %.2lf\n",fmod(A,B));
    printf("Power: %.2lf\n",pow(A,B));
    printf("Root: %.2lf\n",pow(A,(1.0/B)));
return 0;
}

