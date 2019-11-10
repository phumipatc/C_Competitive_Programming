/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
vector< A> g[1010];
priority_queue< A> dijk;
int dist[1010],mark[1010];
A temp;
int main()
{
    int n,m,q,i,u,s,noww;
    scanf("%d %d %d",&n,&m,&q);
    for(i=0;i<=n;i++)
        dist[i]=1<<30;
    dist[1]=0;
    while(m--){
        scanf("%d %d %d",&s,&temp.v,&temp.w);
        g[s].push_back(temp);
    }
    temp.v=1,temp.w=0;
    dijk.push(temp);
    mark[1]=1;
    while(!dijk.empty()){
        temp=dijk.top();
        u=temp.v,noww=temp.w;
        dijk.pop();
        for(i=0;i<g[u].size();i++){
            if(mark[g[u][i].v]==0 && noww+g[u][i].w<dist[g[u][i].v]){
                dist[g[u][i].v]=noww+g[u][i].w;
                temp.v=g[u][i].v,temp.w=noww+g[u][i].w;
                dijk.push(temp);
            }
        }
    }
    while(q--){
        scanf("%d",&s);
        if(dist[s]==1<<30)  printf("-1\n");
        else                printf("%d\n",dist[s]);
    }
    return 0;
}
