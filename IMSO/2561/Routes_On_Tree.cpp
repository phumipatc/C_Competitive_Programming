/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int v,w;
};
struct B{
	int v,w,countt;
	bool operator < (const B&o) const{
		return w>o.w;
	}
};
B now;
vector< A> g[100100];
priority_queue< B> heap;
int dis[100100][6];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,m,k,u,v,w;
	scanf("%d %d %d",&n,&m,&k);
	while(m--){
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w});
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dis[i][j] = 1e9;
	dis[1][0] = 0;
	heap.push({1,0,0});
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		for(int i=0;i<g[now.v].size();i++){
			if(g[now.v][i].w>=0){
				if(dis[g[now.v][i].v][now.countt]>now.w+g[now.v][i].w){
					dis[g[now.v][i].v][now.countt] = now.w+g[now.v][i].w;
					heap.push({g[now.v][i].v,now.w+g[now.v][i].w,now.countt});
				}
			}else{
				if(g[now.v][i].w<=-100){
					if(now.countt+1>k)	continue;
					if(dis[g[now.v][i].v][now.countt+1]>now.w){
						dis[g[now.v][i].v][now.countt+1] = now.w;
						heap.push({g[now.v][i].v,now.w,now.countt+1});
					}
				}else{
					if(dis[g[now.v][i].v][now.countt]>now.w){
						dis[g[now.v][i].v][now.countt] = now.w;
						heap.push({g[now.v][i].v,now.w,now.countt});
					}					
				}
			}
		}
	}
	int ans = 1e9;
	for(int i=0;i<=k;i++)
		ans = min(ans,dis[n][i]);
	if(ans == 1e9)	printf("-1\n");
	else			printf("%d\n",ans);
	return 0;
}
