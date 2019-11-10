/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,st,en;
};
vector<A > g[1010];
struct B{
    int u,w;
    bool operator < (const B&o) const{
        return w>o.w;
    }
};
B now;
priority_queue<B > heap;
int a[1010],way[1010][1010],dis[1010];
int main(){
    int q,n,m,st,en,t,p,u,v,w,sum;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d %d %d",&n,&m,&st,&en,&t,&p);
        sum = -t;
        for(int i=1;i<=p;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                way[i][j] = 1e9;
        while(m--){
            scanf("%d %d %d",&u,&v,&w);
            way[u][v] = way[v][u] = w;
        }
        for(int i=1;i<p;i++){
            g[a[i]].push_back({a[i+1],way[a[i]][a[i+1]],sum,sum+way[a[i]][a[i+1]]});
            g[a[i+1]].push_back({a[i],way[a[i+1]][a[i]],sum,sum+way[a[i]][a[i+1]]});
            sum+=way[a[i]][a[i+1]];
            way[a[i]][a[i+1]] = way[a[i+1]][a[i]] = 1e9;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(way[i][j] == 1e9)    continue;
                g[i].push_back({j,way[i][j],(int)1e9,(int)-1e9});
                way[i][j] = 1e9;
            }
        }
        for(int i=1;i<=n;i++)
            dis[i] = 1e9;
        dis[st] = 0;
        heap.push({st,0});
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            if(now.u == en){
                printf("%d\n",now.w);
                break;
            }
            for(auto x:g[now.u]){
                if(dis[x.v]<=now.w+x.w) continue;
                if(now.w>=x.st && now.w<x.en){
                    dis[x.v] = now.w+x.w+(x.en-now.w);
                    heap.push({x.v,dis[x.v]});
                }else{
                    dis[x.v] = now.w+x.w;
                    heap.push({x.v,dis[x.v]});
                }
            }
        }
        while(!heap.empty())    heap.pop();
        for(int i=1;i<=n;i++)
            g[i].clear();
    }
	return 0;
}
