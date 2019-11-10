/*
    TASK: Important
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL: RYW
    LANG: C
            */
#include<stdio.h>
int main()
{
    double a,b;
    scanf("%lf %lf",&a,&b);
    if(a==0){
        if(b>249){
            printf("%.2lf 0.00\n",125000.0/b);
        }else{
            printf("%.2lf %.2lf\n",125000.0/(500-b),500-(125000.00/(500-b)));
        }
    }else if(b==0){
        if(a>249){
            printf("0.00 %.2lf\n",125000.0/a);
        }else{
            printf("%.2lf %.2lf\n",500-(125000.00/(500-a)),125000.0/(500-a));
            }
    }else{
        if(a<251){
            printf("%.2lf 0.00\n",(500*b-125000)/b);
        }else{
            printf("0.00 %.2lf\n",(500*a-125000)/a);
        }
    }
return 0;
}
