/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,money,oil;
    bool operator < (const A&o) const{
        return money>o.money;
    }
};
vector< A> g[1100];
priority_queue< A> heap;
int dis[1100][1100],oil[1100];
int main()
{
    A now;
    int q,a,b,c,n,m,i,u,cost,fuel,minn,st,en,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        minn=1e9;
        for(i=0;i<n;i++)   scanf("%d",&oil[i]);
        for(i=1;i<=m;i++){
            scanf("%d %d %d",&a,&b,&now.w);
            now.v=b;
            g[a].push_back(now);
            now.v=a;
            g[b].push_back(now);
        }
        scanf("%d %d %d",&c,&st,&en);
        for(i=0;i<n;i++)
            for(j=0;j<=c;j++)
                dis[i][j]=1e9;
        now.v=st,now.w=0,now.money=0,now.oil=0;
        dis[st][0]=0;
        heap.push(now);
        while(!heap.empty()){
            now=heap.top();
            heap.pop();
            u=now.v,cost=now.money,fuel=now.oil;
            if(u==en) break;
            for(i=0;i<g[u].size();i++){
                if(fuel+1<=c&&dis[u][fuel+1]>dis[u][fuel]+oil[u]){
                    dis[u][fuel+1]=dis[u][fuel]+oil[u];
                    now.money=cost+oil[u];
                    now.oil=fuel+1;
                    now.v=u;
                    heap.push(now);
                }
                if(fuel>=g[u][i].w && cost<dis[g[u][i].v][fuel-g[u][i].w]){
                    dis[g[u][i].v][fuel-g[u][i].w]=cost;
                    now.v=g[u][i].v;
                    now.oil=fuel-g[u][i].w;
                    now.money=cost;
                    heap.push(now);
                }
            }
        }
        for(i=0;i<=c;i++)
            minn=min(minn,dis[en][i]);
        if(minn==1e9)   printf("-99\n");
        else            printf("%d\n",minn);
        memset(dis,0,sizeof dis);
        while(!heap.empty()) heap.pop();
        for(i=0;i<n;i++) g[i].clear();
    }
    return 0;
}
