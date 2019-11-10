/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
long long em(int n){
    if(n==0 || n==1)
        return 1;
    if(n%2==0)  return em(n/3)*3;
    if(n%2==1)  return em(2*n)+1;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld",em(n));
    return 0;
}
