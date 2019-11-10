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
        return w<o.w;
    }
};
A now;
priority_queue<A > heap;
vector<A > g[2510];
int dis[2510];
int main(){
    int n,m,u,v,w;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    scanf("%d %d %d",&u,&v,&w);
    dis[u] = 1e9;
    heap.push({u,(int )1e9});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == v){
            printf("%d\n",(int )ceil((double )w/(now.w-1)));
            break;
        }
        for(auto x:g[now.v]){
            if(dis[x.v]>=min(now.w,x.w))    continue;
            dis[x.v] = min(now.w,x.w);
            heap.push({x.v,dis[x.v]});
        }
    }
	return 0;
}
/*
7 10
1 2 30
1 3 15
1 4 10
2 4 25
2 5 60
3 4 40
4 7 35
3 6 20
5 7 20
7 6 30
1 7 99
*/