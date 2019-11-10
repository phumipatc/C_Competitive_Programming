/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator < (const A&o) const {
        return w<o.w;
    }
};
A now;
priority_queue<A > heap;
long long p[200010];
long long fr(long long i){
    if(p[i] == i)   return i;
    else            return p[i] = fr(p[i]);
}
int main(){
    long long n,m,u,v,w;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        p[i] = i;
    while(m--){
        scanf("%lld %lld %lld",&u,&v,&w);
        heap.push({u,v,w-1});
    }
    long long ans = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        u = fr(now.u);
        v = fr(now.v);
        if(u == v)  continue;
        p[u] = v;
        ans+=now.w;
    }
    printf("%lld\n",ans);
	return 0;
}
