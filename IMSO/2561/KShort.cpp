/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	long long v,w,path;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
A now;
vector< A> g[10100];
priority_queue<A > heap;
long long dis[10100][55];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	long long n,m,s,l,u,v,w;
	scanf("%lld %lld %lld %lld",&n,&m,&s,&l);
	while(m--){
		scanf("%lld %lld %lld",&u,&v,&w);
		g[u].push_back({v,w,0});
	}
	while(s--){
		scanf("%lld %lld %lld",&u,&v,&w);
		g[u].push_back({v,w,1});
	}
	for(long long i=1;i<=n;i++)
		for(long long j=0;j<=l;j++)
			dis[i][j] = 1e18;
	dis[1][0] = 0;
	heap.push({1,0,0});
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		for(long long i=0;i<g[now.v].size();i++){
			if(!g[now.v][i].path){
				if(dis[g[now.v][i].v][now.path]>now.w+g[now.v][i].w){
					dis[g[now.v][i].v][now.path] = now.w+g[now.v][i].w;
					heap.push({g[now.v][i].v,now.w+g[now.v][i].w,now.path});
				}
			}else{
				if(now.path+1>l)	continue;
				if(dis[g[now.v][i].v][now.path+1]>now.w+g[now.v][i].w){
					dis[g[now.v][i].v][now.path+1] = now.w+g[now.v][i].w;
					heap.push({g[now.v][i].v,now.w+g[now.v][i].w,now.path+1});
				}
			}
		}
	}
	long long ans = 1e18;
	for(long long i=0;i<=l;i++)
		ans = min(ans,dis[n][i]);
	printf("%lld\n",ans);
	return 0;
}
