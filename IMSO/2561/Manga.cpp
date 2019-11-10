/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int u,v,w;
	bool operator < (const A&o) const{
		return w<o.w;
	}
};
A a[100100],now;
vector< A> g[50100];
priority_queue< A> heap;
int dis[50100];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
	int l = 1,r = n,ch = 0;
	while(l<r){
		int mid = (l+r)/2;
		for(int i=1;i<=n;i++){
			dis[i] = 1e9;
			g[i].clear();
		}
		for(int i=1;i<=mid;i++){
			g[a[i].u].push_back({a[i].v,0,a[i].w});
			g[a[i].v].push_back({a[i].u,0,a[i].w});
		}
		dis[1] = 0;
		heap.push({1,0,0});
		while(!heap.empty()){
			now = heap.top();
			heap.pop();
			for(int i=0;i<g[now.u].size();i++){
				if(now.w+g[now.u][i].w>k)	continue;
				if(dis[g[now.u][i].u]>now.w+g[now.u][i].w){
					dis[g[now.u][i].u] = now.w+g[now.u][i].w;
					heap.push({g[now.u][i].u,0,dis[g[now.u][i].u]});
				}
			}
		}
		if(dis[n]>k)	l = mid+1;
		else			r = mid,ch = 1;
	}
	if(ch){
		printf("%d\n",l);
		return 0;
	}
	for(int i=1;i<=n;i++){
		dis[i] = 1e9;
		g[i].clear();
	}
	for(int i=1;i<=r;i++){
		g[a[i].u].push_back({a[i].v,0,a[i].w});
		g[a[i].v].push_back({a[i].u,0,a[i].w});
	}
	dis[1] = 0;
	heap.push({1,0,0});
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		for(int i=0;i<g[now.u].size();i++){
			if(now.w+g[now.u][i].w>k)	continue;
			if(dis[g[now.u][i].u]>now.w+g[now.u][i].w){
				dis[g[now.u][i].u] = now.w+g[now.u][i].w;
				heap.push({g[now.u][i].u,0,dis[g[now.u][i].u]});
			}
		}
	}
	if(dis[n]<=k)	printf("%d\n",r);
	else			printf("-1\n");
	return 0;
}
