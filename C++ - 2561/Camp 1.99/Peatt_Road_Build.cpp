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
priority_queue<A > heap;
int dis[1010][2];
vector<A > g[1010];
int main(){
    int n,m,u,v,w,ch,ans = 1e9,temp;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w,i,0});
        g[v].push_back({u,w,i,0});
    }
    for(int i=1;i<=n;i++)
        dis[i][0] = dis[i][1] = 1e9;
    heap.push({1,0,1,0});
    dis[1][1] = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == n && now.id == 0){
            printf("%d %d\n",now.maxx,now.w);
            break;
        }
        for(auto x:g[now.v]){
            if(dis[x.v][(now.id+1)%2]<now.w+x.w)    continue;
            dis[x.v][(now.id+1)%2] = now.w+x.w;
            heap.push({x.v,now.w+x.w,(now.id+1)%2,max(now.maxx,x.id)});
        }
    }
	return 0;
}
