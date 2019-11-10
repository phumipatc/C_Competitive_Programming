/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w<o.w;
        else        return v>o.v;
    }
};
vector< A> g[2600];
priority_queue< A> heap;
int dis[2600];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    memset(dis,-1,sizeof dis);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int st,en,k,ans;
    scanf("%d %d %d",&st,&en,&k);
    dis[st]=1e9;
    heap.push({st,dis[st]});
    while(!heap.empty()){
        A now=heap.top();
//        printf("%d %d\n",now.v,now.w);
        heap.pop();
        if(now.v==en){
            ans=dis[en]-1;
            break;
        }
        for(int i=0;i<g[now.v].size();i++){
            if(dis[g[now.v][i].v]<min(now.w,g[now.v][i].w)){
                dis[g[now.v][i].v]=min(now.w,g[now.v][i].w);
                heap.push({g[now.v][i].v,dis[g[now.v][i].v]});
            }
        }
    }
    printf("%d\n",(int)ceil((double)k/(double)ans));
    return 0;
}
