/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define ZERO 100001
using namespace std;
long long a[100010],qs[100010],tree[200010];
void update(long long idx,long long v){
    while(idx<=200003){
        tree[idx]+=v;
        idx+= idx & -idx;
    }
}
long long query(long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    long long n,k;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]>=k) qs[i] = 1;
        else        qs[i] = -1;
        qs[i]+=qs[i-1];
    }
    long long ans = 0;
    update(ZERO,1);
    for(long long i=1;i<=n;i++){
        ans+=query(qs[i]+ZERO);
        update(qs[i]+ZERO,1);
    }
    printf("%lld\n",ans);
	return 0;
}
