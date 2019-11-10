/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int v,w,target;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
A now;
vector<A > g[50100];
priority_queue< A> heap;
int point[50100],dis[50100][32];
int main(){
//	freopen("0_in.txt","r",stdin);
//	freopen("0_out.txt","w",stdout);
	int n,m,l,st,en,u,v,w;
	scanf("%d %d %d %d %d",&n,&m,&l,&st,&en);
	for(int i=1;i<=n;i++)
		scanf("%d",&point[i]);
	while(m--){
		scanf("%d %d %d",&u,&v,&w);
		g[u].push_back({v,w,0});
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=l;j++)
			dis[i][j] = 1e9;
	heap.push({st,0,0});
	dis[st][0] = 0;
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
//		printf("now : %d %d %d\n",now.v,now.w,now.target);
		if(now.target == l && now.v == en){
			printf("%d\n",now.w);
			break;
		}
		if(point[now.v] == now.target)	now.target++;
		for(auto &x:g[now.v]){
			if(dis[x.v][now.target]>now.w+x.w){
//                printf("next : %d %d %d\n",x.v,now.w+x.w,now.target);
				dis[x.v][now.target] = now.w+x.w;
				heap.push({x.v,dis[x.v][now.target],now.target});
			}
		}
	}
    return 0;
}
