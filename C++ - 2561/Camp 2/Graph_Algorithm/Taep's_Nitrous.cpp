/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,k;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
vector<A > g[5010];
priority_queue<A > heap;
int dis[5010][110];
int main(){
    int n,m,kk,u,v,w,ans = 1e9;
    scanf("%d %d %d",&n,&m,&kk);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w,0});
        g[v].push_back({u,w,0});
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=kk;j++)
            dis[i][j] = 1e9;
    dis[1][0] = 0;
    heap.push({1,0,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == n && now.k == 0)    break;
        for(auto x:g[now.v]){
            if(dis[x.v][now.k]>dis[now.v][now.k]+x.w){
                dis[x.v][now.k] = dis[now.v][now.k]+x.w;
                heap.push({x.v,dis[now.v][now.k]+x.w,now.k});
            }
            if(now.k == kk) continue;
            if(dis[x.v][now.k+1]>dis[now.v][now.k]+(x.w/2)){
                dis[x.v][now.k+1] = dis[now.v][now.k]+(x.w/2);
                heap.push({x.v,dis[now.v][now.k]+(x.w/2),now.k+1});
            }
        }
    }
    for(int i=0;i<=kk;i++)
        ans = min(ans,dis[n][i]);
    printf("%d\n%d\n%d\n",dis[n][0],ans,dis[n][0]-ans);
	return 0;
}
