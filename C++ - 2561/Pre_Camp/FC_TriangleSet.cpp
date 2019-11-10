/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[400100];
int main(){
    long long n,i,ans=0,idx;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        idx = lower_bound(a+1,a+n+1,a[i]+a[i+1])-a-1;
        ans = max(ans,idx-i+1);
    }
    printf("%lld\n",ans);
    return 0;
}
