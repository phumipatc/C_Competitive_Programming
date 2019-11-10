/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    long long i,n,ans=0;
    scanf("%lld",&n);
    for(i=5;i<=n;i*=5)
        ans+=n/i;
    printf("%lld\n",ans);
    return 0;
}
