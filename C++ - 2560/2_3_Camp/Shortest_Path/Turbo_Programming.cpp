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
priority_queue< A> heap;
int dist[1010],mark[1010];
A temp;
int main()
{
    int n,m,q,i,u,s,noww;
    scanf("%d %d %d",&n,&m,&q);
    for(i=0;i<=n;i++)
        dist[i]=1e9;
    dist[1]=0;
    while(m--){
        scanf("%d %d %d",&s,&temp.v,&temp.w);
        g[s].push_back(temp);
    }
    temp.v=1,temp.w=0;
    heap.push(temp);
    mark[1]=1;
    while(!heap.empty()){
        temp=heap.top();
        u=temp.v,noww=temp.w;
        heap.pop();
        for(i=0;i<g[u].size();i++){
            if(mark[g[u][i].v]==0 && noww+g[u][i].w<dist[g[u][i].v]){
                dist[g[u][i].v]=noww+g[u][i].w;
                temp.v=g[u][i].v,temp.w=noww+g[u][i].w;
                heap.push(temp);
            }
        }
    }
    while(q--){
        scanf("%d",&s);
        if(dist[s]==1e9)    printf("-1\n");
        else                printf("%d\n",dist[s]);
    }
    return 0;
}
