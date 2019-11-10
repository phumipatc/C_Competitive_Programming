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
vector<A > g[10010];
priority_queue<A > heap;
int dis[125];
int main(){
    int n,w;
    char u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c %c %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1;i<=123;i++)
        dis[i] = 1e9;
    heap.push({'Z',0});
    dis['Z'] = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(auto x:g[now.v]){
            if(dis[x.v]>now.w+x.w){
                dis[x.v] = now.w+x.w;
                heap.push({x.v,dis[x.v]});
            }
        }
    }
    int minn = 1e9,ans;
    for(int i=65;i<90;i++){
        if(dis[i] == 1e9)   continue;
        if(minn>dis[i]){
            minn = dis[i];
            ans = i;
        }
    }
    printf("%c %d\n",ans,dis[ans]);
	return 0;
}
