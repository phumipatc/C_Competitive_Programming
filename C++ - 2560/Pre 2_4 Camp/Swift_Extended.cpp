/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w,idx,id;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
vector< A> g[110];
priority_queue< A> heap;
long long dis[110][10010];
int main(){
    long long i,j,n,m,u,v,w;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        g[u].push_back({v,w,0,i});
        g[v].push_back({u,w,0,i});
    }
    for(i=1;i<=n;i++)
        for(j=0;j<=m;j++)
            dis[i][j]=1e18;
    for(i=0;i<=10000;i++)
        dis[1][i]=0;
    long long ans=1e9,ans2=-1;
    for(int i = 0 ; i <= m ; i++){
        heap.push({1,0,i,0});
        while(!heap.empty()){
            A now=heap.top();
            heap.pop();
            if(now.v==n){
                if(now.idx==0)  ans=min(ans,now.w);
                else            ans2=max(ans2,now.w);
                break;
            }
            for(int i=0;i<g[now.v].size();i++){
                if(g[now.v][i].id==now.idx){
                    if(dis[g[now.v][i].v][now.idx]>now.w+(2*g[now.v][i].w)){
                        dis[g[now.v][i].v][now.idx]=now.w + 2*g[now.v][i].w;
                        heap.push({g[now.v][i].v,now.w+2*g[now.v][i].w,now.idx,0});
                    }
                }else{
                    if(dis[g[now.v][i].v][now.idx]>now.w+g[now.v][i].w){
                        dis[g[now.v][i].v][now.idx]=now.w+g[now.v][i].w;
                        heap.push({g[now.v][i].v,now.w+g[now.v][i].w,now.idx,0});
                    }
                }
            }
        }
        while(!heap.empty())   heap.pop();
    }
    printf("%lld\n",ans2-ans);
    return 0;
}
