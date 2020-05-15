/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w,id;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A a[200010],now;
priority_queue<A > heap;
struct B{
    long long v,w;
};
vector<B > g[200010];
long long p[200010],mark[200010],LCA[200010][20],weight[200010][20],lv[200010];
long long find_root(long long u){
    if(p[u] == u)   return u;
    else            return p[u] = find_root(p[u]);
}
void dfs(long long u,long long pa,long long w,long long state){
    // printf("%lld\n",u);
    LCA[u][0] = pa;
    lv[u] = state;
    weight[u][0] = w;
    for(long long i=1;i<18;i++){
        LCA[u][i] = LCA[LCA[u][i-1]][i-1];
        weight[u][i] = max(weight[u][i-1],weight[LCA[u][i-1]][i-1]);
    }
    for(auto x:g[u]){
        if(x.v == pa)   continue;
        dfs(x.v,u,x.w,state+1);
    }
}
int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        p[i] = i;
    for(long long i=1;i<=m;i++){
        scanf("%lld %lld %lld",&a[i].u,&a[i].v,&a[i].w);
        a[i].id = i;
        heap.push(a[i]);
    }
    long long ru,rv,sum = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = find_root(now.u);
        rv = find_root(now.v);
        if(ru == rv)    continue;
        g[now.u].push_back({now.v,now.w});
        g[now.v].push_back({now.u,now.w});
        // printf("MST: %lld %lld %lld\n",now.u,now.v,now.w);
        mark[now.id] = 1;
        p[ru] = rv;
        sum+=now.w;
    }
    dfs(1,0,0,1);
    for(long long i=1;i<=m;i++){
        if(mark[i]){
            printf("%lld\n",sum);
            continue;
        }
        long long tu = a[i].u,tv = a[i].v,maxx = 0;
        if(lv[tu]>lv[tv])   swap(tu,tv);
        for(long long i=17;i>=0;i--){
            if(lv[LCA[tv][i]]<lv[tu])   continue;
            maxx = max(maxx,weight[tv][i]);
            tv = LCA[tv][i];
        }
        // printf("processing: %lld %lld %lld\n",tu,tv,maxx);
        if(tu!=tv){
            for(long long i=17;i>=0;i--){
                if(LCA[tu][i] == LCA[tv][i])    continue;
                maxx = max(maxx,max(weight[tu][i],weight[tv][i]));
                tu = LCA[tu][i],tv = LCA[tv][i];
            }
            maxx = max(maxx,max(weight[tu][0],weight[tv][0]));
        }
        printf("%lld\n",sum-maxx+a[i].w);
    }
    // printf("%lld\n",LCA[7][1]);
	return 0;
}
/*
7 14
2 4 25
6 4 5
5 6 3
5 7 9
6 1 17
4 7 6
5 4 25
1 2 23
2 3 15
5 1 10
7 6 21
3 7 5
5 3 4
5 2 15
*/