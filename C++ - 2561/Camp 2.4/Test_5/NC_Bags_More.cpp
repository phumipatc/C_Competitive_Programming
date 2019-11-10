/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long w,v;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w<o.w;
        else        return v>o.v;
    }
};
A a[300010];
priority_queue<long long > heap;
long long b[300010];
int main(){
    long long n,k,w,v;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf("%lld %lld",&w,&v);
        a[i] = {w,v};
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=k;i++)
        scanf("%lld",&b[i]);
    sort(b+1,b+k+1);
    long long idx = 1,ans = 0;
    for(long long i=1;i<=k;i++){
        while(idx<=n && a[idx].w<=b[i]) heap.push(a[idx].v),idx++;
        if(heap.empty())                continue;
        ans+=heap.top();
        heap.pop();
    }
    printf("%lld\n",ans);
	return 0;
}