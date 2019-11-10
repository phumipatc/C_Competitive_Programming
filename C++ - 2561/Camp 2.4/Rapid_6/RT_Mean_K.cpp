/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[1000010],b[1000010],tree[1000010],comp[1000010];
void update(long long idx,long long v){
    while(idx<=n+3){
        tree[idx]+=v;
        idx+=(idx&(-idx));
    }
}
long long query(long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    long long k,ans = 0,idx = 1,now;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    scanf("%lld",&k);
    for(long long i=1;i<=n;i++)
        b[i] = a[i] = a[i]-k+a[i-1];
    sort(b,b+n+1);
    for(long long i=0;i<=n;i++){
        if(b[i] == b[i+1])  continue;
        comp[idx++] = b[i];
    }
    now = lower_bound(comp+1,comp+idx,0)-comp;
    update(now,1);
    for(long long i=1;i<=n;i++){
        now = lower_bound(comp+1,comp+idx,a[i])-comp;
        ans+=query(now);
        update(now,1);
    }
    printf("%lld\n",ans);
    return 0;
}
