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
vector< A> g[210];
priority_queue< B> heap;
long long friends[210],dis[210][1<<16],num[210],way[210][210];
int main(){

    long long n,m,k,i,now,u,v,w,j,nowdis,nowbit,temp,l;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=0;i<k;i++){
        scanf("%lld",&now);
        friends[now]=1;
        num[now]=i;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            way[i][j]=1e18;
    for(i=1;i<=n;i++)
        way[i][i]=0;
    for(i=0;i<m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        way[u][v]=way[v][u]=w;
    }
    for(l=1;l<=n;l++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                way[i][j]=min(way[i][j],way[i][l]+way[l][j]);
    for(i=2;i<n;i++){
        if(friends[i]){
            g[1].push_back({i,way[1][i]});
            g[i].push_back({1,way[1][i]});
            g[n].push_back({i,way[n][i]});
            g[i].push_back({n,way[n][i]});
        }
    }
    for(i=2;i<n;i++){
        for(j=i+1;j<n;j++){
            if(friends[i] && friends[j]){
                g[j].push_back({i,way[i][j]});
                g[i].push_back({j,way[i][j]});
            }
        }
    }
    for(i=1;i<=n;i++)
        for(j=0;j<=(1<<k);j++)
            dis[i][j]=1e18;
    dis[1][0]=0;
    heap.push({1,0,0});
    while(!heap.empty()){
        now=heap.top().now;
        nowdis=heap.top().dis;
        nowbit=heap.top().bit;
        heap.pop();
        for(i=0;i<g[now].size();i++){
            temp=nowbit;
            if(friends[g[now][i].v])
                temp|=(1<<num[g[now][i].v]);
            if(nowdis + g[now][i].w < dis[g[now][i].v][temp]){
                dis[g[now][i].v][temp]=nowdis+g[now][i].w;
                heap.push({g[now][i].v,dis[g[now][i].v][temp],temp});
            }
        }
    }
    printf("%lld\n",dis[n][(1<<k)-1]);
    return 0;
}
/*
7 10 1
4
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4


7 10 2
3 6
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4
*/
