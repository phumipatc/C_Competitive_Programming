/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w;
};
A now;
queue< A> que;
struct info{
    long long v,w;
    bool operator < (const info&o) const{
        return w<o.w;
    }
};
info a[100100];
long long mark[100100];
vector< long long> g[100100];
priority_queue< long long> heap;
int main(){
    long long n,m,k,u,v;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i].v);
    for(long long i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    que.push({k,0});
    while(!que.empty()){
        now = que.front();
        que.pop();
        if(mark[now.v]) continue;
        mark[now.v] = 1,a[now.v].w = now.w;
        for(auto x:g[now.v])
            que.push({x,now.w+1});
    }
    long long ans = 0;
    for(int i=1;i<=n;i++)
        if(!mark[i] && a[i].v>0)
            ans+=a[i].v;
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        if(a[i].v<=0)   continue;
        if(heap.size()<a[i].w)
            heap.push(-a[i].v);
        else if(!heap.empty() && -heap.top()<a[i].v){
            heap.pop();
            heap.push(-a[i].v);
        }
    }
    while(!heap.empty()){
        ans-=heap.top();
        heap.pop();
    }
    printf("%lld\n",ans);
    return 0;
}
