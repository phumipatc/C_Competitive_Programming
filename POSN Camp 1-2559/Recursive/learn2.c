/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int fibo(int a){
    if(a<=1)
        return 1;
    else
        return fibo(a-1)+fibo(a-2);
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",fibo(a));
return 0;
}
