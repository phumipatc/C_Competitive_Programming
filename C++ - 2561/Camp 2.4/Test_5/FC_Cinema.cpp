/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w<o.w;
        else        return v>o.v;
    }
};
priority_queue<A > heap;
set<long long > sett;
int main(){
    long long n,f,k,x,ans = 0;
    scanf("%lld %lld",&n,&f);
    for(long long i=1;i<=n;i++){
        scanf("%lld %lld",&k,&x);
        ans+=min(k,x);
        if(k>=x)    heap.push({i,0});
        else        heap.push({i,min(x-k,k)});
    }
    while(f--){
        ans+=heap.top().w;
        sett.insert(heap.top().v);
        heap.pop();
    }
    for(auto x:sett)
        printf("%lld ",x);
    printf("\n%lld\n",ans);
	return 0;
}