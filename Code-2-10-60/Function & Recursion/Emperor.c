/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
long long M(int n)
{
    if(n==0 || n==1)    return 1;
    if(n%2==0)          return M(n/3)*3;
    else                return M(2*n)+1;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld",M(n));
    return 0;
}
