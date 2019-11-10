/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,w,used;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w>o.w;
        else        return used>o.used;
    }
};
A now;
priority_queue<A > heap;
long long mark[50010];
int main(){
    long long n,k,m,u,v,countt = 0;
    scanf("%lld %lld %lld",&n,&k,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld %lld",&u,&v);
        heap.push({i,u,0});
        heap.push({i,v,1});
    }
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(mark[now.u])     continue;
        if(m<now.w)         break;
        if(now.used && !k)  continue;
        countt++;
        m-=now.w;
        mark[now.u] = 1;
        if(now.used)    k--;
    }
    printf("%lld\n",countt);
	return 0;
}
