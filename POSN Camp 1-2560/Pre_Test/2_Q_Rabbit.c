/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    long long q;
    scanf("%lld",&q);
    while(q--)
    {
        long long n,r,t,ans;
        scanf("%lld %lld %lld",&n,&r,&t);
        ans = t-r;
        if(ans < 0) ans+=n;
        if(r==t+1||(t==n&&r==1)) ans=1;
        if(t==r) ans=0;
        printf("%lld\n",ans);
    }
    return 0;
}
