/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int fibo(int n){
    if(n==0)        return 0;
    else if(n==1)   return 1;
    else            return n+fibo(n-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",fibo(n));
    printf("%d\n",(1+n)*n/2);
    return 0;
}
