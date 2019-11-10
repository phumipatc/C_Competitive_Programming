/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long idx,v;
};
long long qs[1000010],dp[1000010];
deque<A > deq;
int main(){
    long long n,k;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&qs[i]);
        qs[i]+=qs[i-1];
    }
    deq.push_back({0,0});
    for(long long i=1;i<=n;i++){
        while(!deq.empty() && qs[i]-qs[deq.front().idx]>k)  deq.pop_front();
        if(deq.empty()) dp[i] = dp[i-1];
        else            dp[i] = max(dp[i-1],qs[i]+deq.front().v);
        while(!deq.empty() && deq.back().v<=dp[i-1]-qs[i])  deq.pop_back();
        deq.push_back({i,dp[i-1]-qs[i]});
        // printf("%lld %lld\n",i,dp[i]);
    }
    printf("%lld\n",dp[n]);
	return 0;
}