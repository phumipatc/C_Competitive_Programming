/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
long GCD(long long i,long long j){
    if(i%j==0)  return j;
    return GCD(j,i%j);
}
int main()
{
    long long n,ans,num;
    scanf("%lld %lld",&n,&ans);
    n--;
    while(n--){
        scanf("%lld",&num);
        ans=ans*num/GCD(num,ans);
    }
    printf("%lld\n",ans);
    return 0;
}
