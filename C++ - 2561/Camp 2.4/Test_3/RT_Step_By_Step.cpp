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
vector<A > g[20010];
priority_queue<A > heap;
int dis[20010],dis2[20010];
int main(){
    int n,m,u,v,w,st,en,k;
    scanf("%d %d",&n,&m);
    scanf("%d %d %d",&st,&en,&k);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=0;i<n;i++)
        dis[i] = dis2[i] = 1e9;
    dis[st] = 0;
    heap.push({st,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto x:g[now.v]){
            if(dis[x.v]<=now.w+x.w) continue;
			dis[x.v] = now.w+x.w;
			heap.push({x.v,dis[x.v]});
        }
    }
	dis2[en] = 0;
    heap.push({en,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto x:g[now.v]){
            if(dis2[x.v]<=now.w+x.w)	continue;
			dis2[x.v] = now.w+x.w;
			heap.push({x.v,dis2[x.v]});
        }
    }
	for(int i=0;i<n;i++){
		if(dis[i]+dis2[i]<=k)	continue;
		printf("%d ",i);
	}
	return 0;
}
/*
5 6
0 4 17
0 1 6
1 2 5
3 2 8
2 4 8
0 3 5
4 1 9
*/