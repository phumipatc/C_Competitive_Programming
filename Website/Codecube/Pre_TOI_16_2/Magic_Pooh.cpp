/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int v,w,ch;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
A now;
priority_queue<A > heap;
vector<A > g[100010];
int mark[100010][2];
int main(){
	// ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,k,t,u,v,w;
	scanf("%d %d %d %d",&n,&m,&k,&t);
	while(m--){
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w,0});
		g[v].push_back({u,w,0});
	}
	heap.push({1,0,0});
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		if(now.w>t)						continue;
		if(mark[now.v][now.ch])			continue;
		// printf("now: %d %d\n",now.v,now.w);
		mark[now.v][now.ch] = 1;
		if(now.v == n){
			printf("Happy Winnie the Pooh :3\n%d\n",now.w);
			return 0;
		}
		for(auto x:g[now.v]){
			// printf("next: %d\n",x.v);
			if(!now.ch)	heap.push({x.v,now.w+k,1});
			heap.push({x.v,now.w+x.w,now.ch});
		}
	}
	printf("No Honey TT\n");
	return 0;
}