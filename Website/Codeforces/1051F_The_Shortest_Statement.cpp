/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
priority_queue<A > MST;
struct B{
    long long v,w;
    bool operator < (const B&o) const{
        return w>o.w;
    }
};
priority_queue<B > Dijk;
vector<B > g[100010],gm[100010];
vector<long long > head;
long long p[100010],dis[50][100010],sum[100010],LCA[100010][18],lv[100010];
long long find_root(long long u){
    if(p[u] == u)   return u;
    else            return p[u] = find_root(p[u]);
}
void dfs(long long u,long long pa,long long state){
    LCA[u][0] = pa;
    lv[u] = state;
    for(long long i=1;i<17;i++)
        LCA[u][i] = LCA[LCA[u][i-1]][i-1];
    for(auto x:gm[u]){
        if(x.v == pa)   continue;
        sum[x.v] = sum[u]+x.w;
        dfs(x.v,u,state+1);
    }
}
long long dis_LCA(long long u,long long v){
    if(lv[u]>lv[v]) swap(u,v);
    long long ret = sum[u]+sum[v];
    for(long long i=16;i>=0;i--){
        if(lv[LCA[v][i]]<lv[u]) continue;
        v = LCA[v][i];
    }
    if(u!=v){
        for(long long i=16;i>=0;i--){
            if(LCA[u][i] == LCA[v][i])  continue;
            u = LCA[u][i],v = LCA[v][i];
        }
        u = LCA[u][0];
        v = LCA[v][0];
    }
    return ret-(2*sum[u]);
}
int main(){
    long long n,m,u,v,w;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        MST.push({u,v,w});
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(long long i=1;i<=n;i++)
        p[i] = i;
    while(!MST.empty()){
        A now = MST.top();
        MST.pop();
        long long pu = find_root(now.u);
        long long pv = find_root(now.v);
        if(pu == pv){
            head.push_back(now.u);
            head.push_back(now.v);
            continue;
        }
        p[pu] = pv;
        gm[now.u].push_back({now.v,now.w});
        gm[now.v].push_back({now.u,now.w});
    }
    sort(head.begin(),head.end());
    head.resize(unique(head.begin(),head.end())-head.begin());
    for(long long i=0;i<head.size();i++)
        for(long long j=1;j<=n;j++)
            dis[i][j] = 1e18;
    for(long long i=0;i<head.size();i++){
        dis[i][head[i]] = 0;
        Dijk.push({head[i],0});
        while(!Dijk.empty()){
            B now = Dijk.top();
            Dijk.pop();
            for(auto x:g[now.v]){
                if(dis[i][x.v]<=now.w+x.w)  continue;
                dis[i][x.v] = now.w+x.w;
                Dijk.push({x.v,now.w+x.w});
            }
        }
    }
    dfs(1,0,1);
    long long q,ans;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&u,&v);
        ans = dis_LCA(u,v);
        for(long long i=0;i<head.size();i++)
            ans = min(ans,dis[i][u]+dis[i][v]);
        printf("%lld\n",ans);
    }
	return 0;
}