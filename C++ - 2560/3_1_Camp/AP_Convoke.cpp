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
struct B{
    long long now,dis,bit;
    bool operator <(const B & o)const{
        return dis>o.dis;
    }
};
B now;
vector< A> g[210];
priority_queue< B> heap;
long long fr[210],dis[210][1<<16],num[210],way[210][210];
int main(){

    long long n,m,k,u,v,w,tmp,noww;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=0;i<k;i++){
        scanf("%lld",&noww);
        fr[noww] = 1;
        num[noww] = i;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            way[i][j] = 1e18;
    for(int i=1;i<=n;i++)
        way[i][i] = 0;
    for(int i=0;i<m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        way[u][v] = way[v][u] = w;
    }
    for(int l=1;l<=n;l++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                way[i][j]=min(way[i][j],way[i][l]+way[l][j]);
    for(int i=2;i<n;i++){
        if(fr[i]){
            g[1].push_back({i,way[1][i]});
            g[i].push_back({1,way[1][i]});
            g[n].push_back({i,way[n][i]});
            g[i].push_back({n,way[n][i]});
        }
    }
    for(int i=2;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(fr[i] && fr[j]){
                g[j].push_back({i,way[i][j]});
                g[i].push_back({j,way[i][j]});
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=(1<<k);j++)
            dis[i][j] = 1e18;
    dis[1][0] = 0;
    heap.push({1,0,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(int i=0;i<g[now.now].size();i++){
            tmp = now.bit;
            if(fr[g[now.now][i].v])
                tmp|=(1<<num[g[now.now][i].v]);
            if(now.dis + g[now.now][i].w < dis[g[now.now][i].v][tmp]){
                dis[g[now.now][i].v][tmp]=now.dis+g[now.now][i].w;
                heap.push({g[now.now][i].v,dis[g[now.now][i].v][tmp],tmp});
            }
        }
    }
    printf("%lld\n",dis[n][(1<<k)-1]);
    return 0;
}
