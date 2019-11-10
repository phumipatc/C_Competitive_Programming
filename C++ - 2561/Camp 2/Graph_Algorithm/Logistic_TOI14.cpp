/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
};
vector<A > g[110];
struct B{
    int v,w,oil,ch;
    bool operator < (const B&o) const{
        return w>o.w;
    }
};
B now;
priority_queue<B > heap;
int price[110],dis[110][110][2];
int main(){
    int n,st,en,capa,m,u,v,w;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&price[i]);
    scanf("%d %d %d %d",&st,&en,&capa,&m);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=capa;j++)
            dis[i][j][0] = dis[i][j][1] = 1e9;
    dis[st][0][1] = 0;
    heap.push({st,0,0,1});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == en && now.oil == capa){
            printf("%d\n",now.w);
            break;
        }
        if(now.oil<capa && dis[now.v][now.oil+1][now.ch]>now.w+price[now.v]){
            dis[now.v][now.oil+1][now.ch] = now.w+price[now.v];
            heap.push({now.v,now.w+price[now.v],now.oil+1,now.ch});
        }
        if(now.ch && dis[now.v][capa][0]>now.w){
            dis[now.v][capa][0] = now.w;
            heap.push({now.v,now.w,capa,0});
        }
        for(auto x:g[now.v]){
            if(x.w>now.oil)                             continue;
            if(dis[x.v][now.oil-x.w][now.ch]<=now.w)    continue;
            dis[x.v][now.oil-x.w][now.ch] = now.w;
            heap.push({x.v,now.w,now.oil-x.w,now.ch});
        }
    }
	return 0;
}
