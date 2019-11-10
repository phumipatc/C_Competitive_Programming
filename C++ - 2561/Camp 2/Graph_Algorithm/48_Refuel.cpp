/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
};
vector<A > g[1010];
struct B{
    int v,w,oil;
    bool operator < (const B&o) const{
        return w>o.w;
    }
};
B now;
priority_queue<B > heap;
int price[1010],dis[1010][110];
int main(){
    int q,n,m,u,v,w,c,st,en;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&price[i]);
        while(m--){
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        scanf("%d %d %d",&c,&st,&en);
        for(int i=0;i<n;i++)
            for(int j=0;j<=c;j++)
                dis[i][j] = 1e9;
        dis[st][0] = 0;
        heap.push({st,0,0});
        int ch = 1;
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            if(now.v == en){
                printf("%d\n",now.w);
                ch = 0;
                break;
            }
            if(now.oil<c && dis[now.v][now.oil+1]>now.w+price[now.v]){
                dis[now.v][now.oil+1] = now.w+price[now.v];
                heap.push({now.v,now.w+price[now.v],now.oil+1});
            }
            for(auto x:g[now.v]){
                if(x.w>now.oil)                     continue;
                if(dis[x.v][now.oil-x.w]<=now.w)    continue;
                dis[x.v][now.oil-x.w] = now.w;
                heap.push({x.v,now.w,now.oil-x.w});
            }
        }
        if(ch)  printf("-99\n");
        while(!heap.empty())    heap.pop();
        for(int i=0;i<n;i++)
            g[i].clear();
    }
	return 0;
}
