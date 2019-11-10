/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,s,l,countt;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
vector< A> g[80010];
priority_queue< A> heap;
int sp[10] = {1,2,4,8,16,32,64,128,256};
int potion[80010],dis[10][80010];
int main(){
    int n,m,l,q,u,v,w,num;
    scanf("%d %d %d %d",&n,&m,&l,&q);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w,0,0,0});
    }
    for(int i=1;i<=l;i++){
        scanf("%d",&num);
        potion[num] = 1;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=8;j++)
            dis[j][i] = 1e9;
    heap.push({1,0,0,0,0});
    dis[0][1] = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(int i=0;i<g[now.v].size();i++){
            if(potion[now.v] && now.l!=now.v && now.countt!=q){
                if(dis[now.countt+1][g[now.v][i].v] > now.w+(g[now.v][i].w/sp[now.s+1])){
                    dis[now.countt+1][g[now.v][i].v] = now.w+(g[now.v][i].w/sp[now.s+1]);
                    heap.push({g[now.v][i].v,dis[now.countt+1][g[now.v][i].v],now.s+1,now.v,now.countt+1});
                }
            }
            if(dis[now.countt][g[now.v][i].v] > now.w+(g[now.v][i].w/sp[now.s])){
                dis[now.countt][g[now.v][i].v] = now.w+(g[now.v][i].w/sp[now.s]);
                heap.push({g[now.v][i].v,dis[now.countt][g[now.v][i].v],now.s,now.l,now.countt});
            }
        }
    }
    int ans = 1e9;
    for(int i=0;i<=8;i++)
        ans = min(ans,dis[i][n]);
    printf("%d\n",ans);
    return 0;
}
