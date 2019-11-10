/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector < long long > g[1000100];
long long dis[510][510];
int main(){
    long long n,m,k,i,j,now,u,v,ans;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
            if(i == j)	dis[i][j] = 0;
            else		dis[i][j] = 1e18;
        }
    }
    for(i=1;i<=m;i++){
        scanf("%lld",&k);
        while(k--){
            scanf("%lld",&now);
            g[now].push_back(i);
        }
    }
    for(i=1;i<=n;i++)
        for(j=0;j<g[i].size();j++)
            for(k=j+1;k<g[i].size();k++)
                if(g[i][j] != g[i][k])
                    dis[g[i][j]][g[i][k]] = dis[g[i][k]][g[i][j]] = 1;
    for(k=1;k<=m;k++)
        for(i=1;i<=m;i++)
            for(j=1;j<=m;j++)
                if(dis[i][k]!=1e18 && dis[k][j]!=1e18)
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    scanf("%lld",&k);
    while(k--){
        scanf("%lld %lld",&u,&v);
        ans = 1e18;
        for(i=0;i<g[u].size();i++)
            for(j=0;j<g[v].size();j++)
                ans = min(ans,dis[g[u][i]][g[v][j]]);
        if(ans==1e18)
            printf("impossible\n");
        else
            printf("%lld\n",ans);
    }
    return 0;
}
/*
5 2
GOLF
JUMP
FOG
BEAM
TAN
*/
