/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long h,r;
};
A a[20];
long long n,ans,aa,bb;
void permute(long long now,long long sum,long long maxx,long long minn){
    if(now == n+1){
        if(maxx == 0 && minn == 0)
            ans = max(ans,0ll);
        else
            ans = max(ans,(aa*sum)-(bb*(maxx-minn)));
        return ;
    }
    permute(now+1,sum,maxx,minn);
    if(now == 1)
        permute(now+1,sum+a[now].r,a[now].h,a[now].h);
    else
        permute(now+1,sum+a[now].r,max(maxx,a[now].h),min(minn,a[now].h));
}
int main(){
    scanf("%lld %lld %lld",&n,&aa,&bb);
    for(long long i=1;i<=n;i++)
        scanf("%lld %lld",&a[i].h,&a[i].r);
    permute(1,0,0,0);
    printf("%lld\n",ans);
    return 0;
}
