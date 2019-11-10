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
priority_queue<A > heap;
vector<int > g[65];
int dis[65];
int main(){
    int m,s,e,u,v;
    scanf("%d %d %d",&m,&s,&e);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=60;i++)
        dis[i] = 1e9;
    dis[s] = 0;
    heap.push({s,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == e){
            printf("%d\n",dis[e]);
            break;
        }
        for(auto x:g[now.v]){
            if(dis[x]>now.w+1){
                dis[x] = now.w+1;
                heap.push({x,dis[x]});
            }
        }
    }
	return 0;
}
