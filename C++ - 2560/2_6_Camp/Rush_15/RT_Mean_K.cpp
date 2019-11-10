/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000005],n,qs[1000005],tree[1000005],compress[1000005],temp[1000005];
void update(long long idx,long long v){
    while(idx<=n+1){
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
        temp[i] = qs[i] = a[i]-k+qs[i-1];
    sort(temp,temp+n+1);
    for(long long i=0;i<=n;i++){
        if(temp[i] == temp[i+1])  continue;
        compress[idx++] = temp[i];
    }
    now = lower_bound(compress+1,compress+idx,0)-compress;
    update(now,1);
    for(long long i=1;i<=n;i++){
        now = lower_bound(compress+1,compress+idx,qs[i])-compress;
        ans+=query(now);
        update(now,1);
    }
    printf("%lld\n",ans);
    return 0;
}
