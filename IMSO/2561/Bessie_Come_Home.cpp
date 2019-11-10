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
        return w>o.w;
    }
};
A now;
vector<A > g[130];
priority_queue< A> heap;
int dis[130];
int main(){
    int n,w;
    char u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c %c %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    memset(dis,127,sizeof dis);
    dis['Z'] = 0;
    heap.push({'Z',0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto &x:g[now.v]){
            if(dis[x.v]>now.w+x.w){
                dis[x.v] = now.w+x.w;
                heap.push({x.v,dis[x.v]});
            }
        }
    }
    int ans,minn = 1e9;
    for(int i='A';i<'Z';i++){
        if(minn>dis[i]){
            minn = dis[i];
            ans = i;
        }
    }
    printf("%c %d\n",ans,minn);
    return 0;
}
