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
vector<A > g[10010];
int dis[10010][2];
int main(){
    int n,m,st,en,d,u,v,w;
    scanf("%d %d %d %d %d",&n,&m,&st,&en,&d);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<2;j++)
            dis[i][j] = 1e9;
    dis[st][0] = 0;
    heap.push({st,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto x:g[now.v]){
            if(dis[x.v][0]<=now.w+x.w)  continue;
            dis[x.v][0] = now.w+x.w;
            heap.push({x.v,dis[x.v][0]});
        }
    }
    if(dis[en][0]<=d){
        printf("%d %d %d\n",en,dis[en][0],0);
        return 0;
    }
    dis[en][1] = 0;
    heap.push({en,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto x:g[now.v]){
            if(dis[x.v][1]<=now.w+x.w)  continue;
            dis[x.v][1] = now.w+x.w;
            heap.push({x.v,dis[x.v][1]});
        }
    }
    int minn = 1e9,idx;
    for(int i=0;i<n;i++){
        if(dis[i][0]>d) continue;
        if(minn>dis[i][1]){
            minn = dis[i][1];
            idx = i;
        }
    }
    printf("%d %d %d\n",idx,dis[idx][0],dis[idx][1]);
	return 0;
}
/*
8 11
0 5 45
0 1 10
0 2 10
1 3 10
1 5 70
2 3 10
2 4 30
2 6 10
3 5 30
4 5 20
6 7 15
7 5 20
*/