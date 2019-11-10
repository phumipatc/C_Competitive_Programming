/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w,bit;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w>o.w;
        else        return bit<o.bit;
    }
};
A now;
priority_queue<A > heap;
struct B{
    int v,w;
};
vector<B > g[210];
int dis[210][32800],mark[210],fr[20],way[210][210];
int main(){
    int n,m,k,temp = 1,u,v,w;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<k;i++){
        scanf("%d",&fr[i]);
        mark[fr[i]] = temp;
        temp*=2;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j)  way[i][j] = 0;
            else        way[i][j] = 1e9;
        }
    }
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        way[u][v] = way[v][u] = min(way[u][v],w);
    }
    for(int kk=1;kk<=n;kk++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                way[i][j] = min(way[i][j],way[i][kk]+way[kk][j]);
    for(int i=0;i<k;i++){
        g[1].push_back({fr[i],way[1][fr[i]]});
        g[fr[i]].push_back({1,way[1][fr[i]]});
        g[fr[i]].push_back({n,way[n][fr[i]]});
        g[n].push_back({fr[i],way[n][fr[i]]});
        for(int j=i+1;j<k;j++){
            g[fr[i]].push_back({fr[j],way[fr[i]][fr[j]]});
            g[fr[j]].push_back({fr[i],way[fr[i]][fr[j]]});
        }
        for(int j=0;j<=(1<<k)-1;j++)
            dis[fr[i]][j] = 1e9;
    }
    for(int j=0;j<=(1<<k);j++)
        dis[1][j] = dis[n][j] = 1e9;
    dis[1][0] = 0;
    heap.push({1,0,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.u == n && now.bit == (1<<k)-1){
            printf("%d\n",dis[n][(1<<k)-1]);
            break;
        }
        for(auto x:g[now.u]){
            if(dis[x.v][now.bit|mark[x.v]]<=now.w+x.w)  continue;
            dis[x.v][now.bit|mark[x.v]] = now.w+x.w;
            heap.push({x.v,now.w+x.w,now.bit|mark[x.v]});
        }
    }
	return 0;
}
