/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator < (const A&o) const{
        return w<o.w;
    }
};
A now;
priority_queue< A> heap;
long long p[200100];
long long find_root(long long n){
    if(p[n] == n)   return n;
    else            return p[n] = find_root(p[n]);
}
int main(){
    long long n,m,ans = 0,ru,rv;
    scanf("%lld %lld",&n,&m);
    while(m--){
        scanf("%lld %lld %lld",&now.u,&now.v,&now.w);
        now.w--;
        heap.push(now);
    }
    for(long long i=1;i<=n;i++)   p[i] = i;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = find_root(now.u);
        rv = find_root(now.v);
        if(ru == rv)    continue;
        p[ru] = rv;
        ans+=now.w;
    }
    printf("%lld\n",ans);
	return 0;
}
