/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,left;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
vector<A > g[1010];
int dis[1010];
int main(){
    int n,m,st,en,u,v,t,k;
    scanf("%d %d %d %d",&n,&m,&st,&en);
    scanf("%d %d %d %d",&u,&v,&t,&k);
    g[u].push_back({v,t,k});
    while(m--){
        scanf("%d %d %d",&u,&v,&t);
        g[u].push_back({v,t,(int )1e9});
    }
    for(int i=0;i<=n;i++)
        dis[i] = 1e9;
    dis[st] = 0;
    heap.push({st,0,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == en){
            printf("%d\n",dis[en]);
            break;
        }
        for(auto x:g[now.v]){
            if(x.w<0 && now.w<=x.left){
                dis[x.v] = now.w+x.w;
                heap.push({x.v,dis[x.v],0});
            }else if(x.w>0 && dis[x.v]>now.w+x.w){
                dis[x.v] = now.w+x.w;
                heap.push({x.v,dis[x.v],0});
            }
        }
    }
	return 0;
}
