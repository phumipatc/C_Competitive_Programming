/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,k;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
vector<A > g[100010];
priority_queue<A > heap;
int dis[100010][7];
int main(){
    int n,m,k,u,v,w;
    scanf("%d %d %d",&n,&m,&k);
    while(m--){
        scanf("%d %d %d",&u,&v,&w);
        if(w>0)                 g[u].push_back({v,w,0});
        else if(w<=0 && w>-100) g[u].push_back({v,0,0});
        else                    g[u].push_back({v,0,1});
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
            dis[i][j] = 1e9;
    dis[1][0] = 0;
    heap.push({1,0,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.v == n){
            printf("%d\n",now.w);
            return 0;
        }
        for(auto x:g[now.v]){
            if(now.k+x.k>k)                     continue;
            if(dis[x.v][now.k+x.k]<=now.w+x.w)  continue;
            dis[x.v][now.k+x.k] = now.w+x.w;
            heap.push({x.v,now.w+x.w,now.k+x.k});
        }
    }
    printf("-1\n");
	return 0;
}