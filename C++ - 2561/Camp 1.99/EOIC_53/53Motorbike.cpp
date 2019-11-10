/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w;
    bool operator < (const A&o) const{
        if(u!=o.u)  return u<o.u;
        else        return w<o.w;
    }
};
A now,a[200010];
queue<A > que;
vector<A > g[50010];
pair<int ,int > pa[200010];
int dis[50010];
int main(){
    int n,p,m,e,u,v,w;
    scanf("%d %d %d %d",&n,&p,&m,&e);
    for(int i=1;i<=p;i++)
        scanf("%d %d",&pa[i].first,&pa[i].second);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++)
        dis[i] = 1e9;
    dis[e] = 0;
    que.push({e,0});
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(auto x:g[now.u]){
            if(dis[x.u]>now.w+x.w){
                dis[x.u] = now.w+x.w;
                que.push({x.u,dis[x.u]});
            }
        }
    }
    for(int i=1;i<=p;i++){
        a[i].u = dis[pa[i].first]/pa[i].second;
        a[i].w = i;
    }
    sort(a+1,a+p+1);
    for(int i=1;i<=p;i++)
        printf("%d ",a[i].w);
    return 0;
}
