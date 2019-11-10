/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1000010];
int dis[510][510];
int main(){
    int n,m,temp,num;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&temp);
        while(temp--){
            scanf("%d",&num);
            g[num].push_back(i);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i == j)  dis[i][i] = 0;
            else        dis[i][j] = 1e9;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            for(int k=j+1;k<g[i].size();k++)
                if(g[i][j]!=g[i][k])
                    dis[g[i][j]][g[i][k]] = dis[g[i][k]][g[i][j]] = 1;
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    int q,u,v,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&u,&v);
        ans = 1e9;

        for(auto x:g[u]){
            for(auto y:g[v]){
                ans = min(ans,dis[x][y]);
            }
        }
        if(ans == 1e9)  printf("impossible\n");
        else            printf("%d\n",ans);
    }
	return 0;
}
