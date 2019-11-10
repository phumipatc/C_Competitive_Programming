/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
int dis[310][310],p[310],in[310];
int find_root(int u){
    if(p[u] == u)   return u;
    else            return p[u] = find_root(p[u]);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&dis[i][j]);
            if(j<=i)    continue;
            heap.push({i,j,dis[i][j]});
        }
    }
    for(int i=1;i<=n;i++)
        p[i] = i;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        int pu = find_root(now.u);
        int pv = find_root(now.v);
        if(pu == pv)    continue;
        p[pu] = pv;
        in[now.u]++,in[now.v]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i]<3) continue;
        printf("%d\n",i);
        if(k == 2)  printf("%d\n",in[i]);
        break;
    }
	return 0;
}