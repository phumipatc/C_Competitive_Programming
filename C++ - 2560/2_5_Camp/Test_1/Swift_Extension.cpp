/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w,idx;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
vector< A> g[10005];
long long dis[105];
priority_queue< A> heap;
int main(){
    long long n,m,u,v,w,minn,maxx=-1;
    cin >> n >> m;
    for(long long i=1;i<=m;i++){
        cin >> u >> v >> w;
        g[u].push_back({v,w,i});
        g[v].push_back({u,w,i});
    }
    for(long long i=0;i<=m;i++){
        for(long long j=1;j<=n;j++)   dis[j] = 1e9;
        dis[1] = 0;
        heap.push({1,0,0});
        while(!heap.empty()){
            A now = heap.top();
            heap.pop();
            if(now.v == n && i == 0){
                minn = now.w;
                break;
            }else if(now.v == n){
                maxx = max(maxx,now.w);
                break;
            }
            for(long long k=0;k<g[now.v].size();k++){
                if(g[now.v][k].idx == i){
                    if(dis[g[now.v][k].v]>now.w+(g[now.v][k].w*2)){
                        dis[g[now.v][k].v] = now.w+(g[now.v][k].w*2);
                        heap.push({g[now.v][k].v,dis[g[now.v][k].v],0});
                    }
                }else{
                    if(dis[g[now.v][k].v]>now.w+g[now.v][k].w){
                        dis[g[now.v][k].v] = now.w+g[now.v][k].w;
                        heap.push({g[now.v][k].v,dis[g[now.v][k].v],0});
                    }
                }
            }
        }
        while(!heap.empty())    heap.pop();
        memset(dis,0,sizeof dis);
    }
    cout << maxx-minn << endl;
    return 0;
}
/*
5 7
1 2 5
1 3 1
2 3 8
2 4 7
3 5 7
3 4 3
4 5 2
*/
