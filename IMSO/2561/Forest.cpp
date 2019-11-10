/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int i,j,w,countt;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
A now;
priority_queue< A> heap;
int a[25][25],dis[25][25][25],dir[2][4] = {{1,-1,0,0},{0,0,1,-1}};
pair<int ,int > mark[25][25];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,p,k,x1,y1,x2,y2,ni,nj;
	scanf("%d %d %d",&n,&p,&k);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	while(p--){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		mark[x1][y1].first = x2;
		mark[x1][y1].second = y2;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int l=0;l<=k;l++)
				dis[i][j][l] = 1e9;
	heap.push({0,0,0,0});
	dis[0][0][0] = 0;
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		if((mark[now.i][now.j].first!=0 || mark[now.i][now.j].second!=0) && now.countt+1<=k){
			if(dis[mark[now.i][now.j].first][mark[now.i][now.j].second][now.countt+1]>now.w){
				dis[mark[now.i][now.j].first][mark[now.i][now.j].second][now.countt+1] = now.w;
				heap.push({mark[now.i][now.j].first,mark[now.i][now.j].second,now.w,now.countt+1});
			}
		}
		for(int i=0;i<4;i++){
			ni = now.i+dir[0][i];
			nj = now.j+dir[1][i];
			if(ni<0 || nj<0 || ni>=n || nj>=n)	continue;
			if(dis[ni][nj][now.countt]<=now.w+a[ni][nj])	continue;
			dis[ni][nj][now.countt] = now.w+a[ni][nj];
			heap.push({ni,nj,now.w+a[ni][nj],now.countt});
		}
	}
	int ans = 1e9;
	for(int i=0;i<=k;i++)
		ans = min(ans,dis[n-1][n-1][i]);
	printf("%d\n",ans);
	return 0;
}
