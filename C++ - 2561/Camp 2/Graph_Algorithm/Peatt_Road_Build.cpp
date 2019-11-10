/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,id,maxx;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w>o.w;
        else        return maxx>o.maxx;
    }
};
A now;
vector<A > g[1010];
priority_queue<A > heap;
int dis[1010][2];
int main(){
    int n,m,l,r,mid,u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w,i});
        g[v].push_back({u,w,i});
    }
    for(int i=1;i<=n;i++)
        dis[i][0] = dis[i][1] = 1e9;
    heap.push({1,0,1,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == n && now.id == 0){
            printf("%d %d",now.maxx,now.w);
            break;
        }
        for(auto x:g[now.v]){
            if(dis[x.v][!now.id]>=now.w+x.w){
                dis[x.v][!now.id] = now.w+x.w;
                heap.push({x.v,now.w+x.w,!now.id,max(now.maxx,x.id)});
            }
        }
    }
	return 0;
}
