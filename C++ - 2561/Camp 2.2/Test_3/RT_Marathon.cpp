/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,str;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
vector<A > g[100010];
int price[100010],dis[100010];
int main(){
    int n,m,k,t,u,v,w,str,maxx = 0;
    scanf("%d %d %d %d",&n,&m,&k,&t);
    while(m--){
        scanf("%d %d %d %d",&u,&v,&str,&w);
        g[u].push_back({v,w,str});
        g[v].push_back({u,w,str});
    }
    for(int i=1;i<=100000;i++)
        price[i] = 1e9;
    for(int i=1;i<=k;i++){
        scanf("%d %d",&w,&str);
        maxx = max(maxx,str);
        price[str] = min(price[str],w);
    }
    int l = 1,r = maxx+1,mid;
    while(l<r){
        mid = (l+r)/2;
        // printf("%d %d %d ",l,r,mid);
        for(int i=2;i<=n;i++)
            dis[i] = 1e9;
        dis[1] = 0;
        heap.push({1,0,mid});
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            if(now.v == n)  break;
            for(auto x:g[now.v]){
                if(x.str>mid)           continue;
                if(dis[x.v]<=now.w+x.w) continue;
                if(now.w+x.w>t)         continue;
                dis[x.v] = now.w+x.w;
                if(x.v == n)            goto next;
                heap.push({x.v,dis[x.v],mid});
            }
        }
        next:;
        // printf("%d\n",dis[n]);
        if(dis[n] == 1e9)   l = mid+1;
        else                r = mid;
        while(!heap.empty())    heap.pop();
    }
    int ans = 1e9;
    for(int i=l;i<=maxx;i++)
        ans = min(ans,price[i]);
    if(ans == 1e9)  printf("-1\n");
    else            printf("%d\n",ans);
	return 0;
}
