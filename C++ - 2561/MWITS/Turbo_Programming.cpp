/*
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
vector<A > g[1010];
priority_queue<A > heap;
int dis[1010];
int main(){
    int n,m,q,u,v,w;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
    }
    memset(dis,-1,sizeof dis);
    dis[1] = 0;
    heap.push({1,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto k:g[now.v]){
            if(dis[k.v] == -1 || dis[k.v]>now.w+k.w){
                dis[k.v] = now.w+k.w;
                heap.push({k.v,now.w+k.w});
            }
        }
    }
    while(q--){
        scanf("%d",&v);
        printf("%d\n",dis[v]);
    }
	return 0;
}
