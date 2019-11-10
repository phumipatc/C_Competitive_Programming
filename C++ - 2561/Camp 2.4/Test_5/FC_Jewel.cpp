/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long idx,v;
    bool operator < (const A&o) const{
        return v<o.v;
    }
};
A now;
priority_queue<A > heap;
long long qs[500010],dp[500010];
int main(){
    long long n,k,maxx = 0;
    scanf("%lld %lld",&n,&k);
    heap.push({0,0});
    for(long long i=1;i<=n;i++){
        scanf("%lld",&qs[i]);
        qs[i]+=qs[i-1];
        heap.push({i,dp[i-1]-qs[i]});
        while(!heap.empty() && qs[i]-qs[heap.top().idx]>k)  heap.pop();
        if(heap.empty())    dp[i] = 0;
        else                dp[i] = qs[i]+heap.top().v;
        maxx = max(maxx,dp[i]);
        // printf("%lld %lld\n",dp[i],maxx);
    }
    printf("%lld\n",maxx);
	return 0;
}