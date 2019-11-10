/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w;
    bool operator < (const A&o) const{
        return  w<o.w;
    }
};
vector<A > g[1010];
priority_queue< A> heap;
int dis[1010][2010];
int main(){
    int n,m,k,u,v,w,st,money;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back({v,0});
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
    }
    scanf("%d %d",&st,&money);
    heap.push({st,0});
    dis[st][0] = 1;
    int ans = 0;
    while(!heap.empty()){
        u = heap.top().u;
        w = heap.top().w;
        heap.pop();
        if(u<=m)
            ans = max(ans,w);
        for(auto &x:g[u]){
            if(!dis[x.u][w+x.w] && w+x.w<=money){
                dis[x.u][w+x.w] = 1;
                heap.push({x.u,w+x.w});
            }
        }
    }
    printf("%d\n",money-ans);
    return 0;
}
