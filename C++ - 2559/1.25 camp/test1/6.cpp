/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
int main()
{
    long long i,a,b,x;
    for(i=0;i<20;i++){
        scanf("%lld %lld",&a,&b);
        x=(4*b-a+2)/2;
        if(a<2*b || x<0)
            printf("0\n");
        else
        printf("%lld\n",x);
    }
return 0;
}
