/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 999999999
using namespace std;
long long a[80010],tree[45][100010];
void update(long long now,long long idx,long long v){
    while(idx<=80000){
        tree[now][idx]+=v;
        idx+=(idx&(-idx));
    }
}
long long query(long long now,long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[now][idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    long long ans = 0,n,k,now;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(long long i=n;i>=1;i--){
        update(1,a[i],1);
        for(long long j=2;j<=k;j++){
            now = (query(j-1,a[i]-1)%MOD);
            update(j,a[i],now);
            if(j == k)  ans = (ans+now)%MOD;
        }
    }
    printf("%lld\n",ans%MOD);
    return 0;
}
