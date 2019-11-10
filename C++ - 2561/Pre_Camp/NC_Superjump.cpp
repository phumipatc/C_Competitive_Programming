/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v;
    double w;
    int state;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
vector<A > g[10010];
double dis[10010][2];
int main(){
    int n,m,u,v;
    double w;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %lf",&u,&v,&w);
        g[u].push_back({v,w,0});
        g[v].push_back({u,w,0});
    }
    for(int i=0;i<n;i++)
        dis[i][0] = dis[i][1] = 1e9;
    dis[0][0] = 0;
    heap.push({0,0,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        // printf("%d %lf %d\n",now.v,now.w,now.state);
        if(now.v == n-1){
            printf("%.2lf\n",now.w);
            break;
        }
        for(auto x:g[now.v]){
            if(!now.state && dis[x.v][1]>now.w+0.14){
                dis[x.v][1] = now.w+0.14;
                heap.push({x.v,dis[x.v][1],1});
            }
            if(dis[x.v][now.state]<=now.w+x.w)  continue;
            dis[x.v][now.state] = now.w+x.w;
            heap.push({x.v,now.w+x.w,now.state});
        }
    }
	return 0;
}
