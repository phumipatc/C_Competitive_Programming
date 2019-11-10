/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,fuel,ticket;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w>o.w;
        else        return fuel<o.fuel;
    }
};
A now;
priority_queue<A > heap;
vector<A > g[110];
int val[110],dis[110][110][2];
int main(){
    int n,st,en,capa,m,u,v,w;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]);
    scanf("%d %d %d %d",&st,&en,&capa,&m);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w,0,0});
        g[v].push_back({u,w,0,0});
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=capa;j++)
            dis[i][j][0] = dis[i][j][1] = 1e9;
    dis[st][0][1]  = 0;
    heap.push({st,0,0,1});
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		if(now.v == en && now.fuel == capa){
			printf("%d\n",now.w);
			break;
		}
		if(now.ticket){
			if(dis[now.v][capa][0]>now.w){
				dis[now.v][capa][0] = now.w;
				heap.push({now.v,now.w,capa,0});
			}
		}
		if(now.fuel<capa){
			if(dis[now.v][now.fuel+1][now.ticket]>now.w+val[now.v]){
				dis[now.v][now.fuel+1][now.ticket] = now.w+val[now.v];
				heap.push({now.v,now.w+val[now.v],now.fuel+1,now.ticket});
			}
		}
		for(auto x:g[now.v]){
			if(now.fuel<x.w)	continue;
			if(dis[x.v][now.fuel-x.w][now.ticket]<=now.w)	continue;
			dis[x.v][now.fuel-x.w][now.ticket] = now.w;
			heap.push({x.v,now.w,now.fuel-x.w,now.ticket});
		}
	}
	return 0;
}