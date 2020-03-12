/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int i,j,w;
};
A now;
queue<A > que;
pair<int ,int > st,en;
int dis[1010][1010],dir[2][4] = {{1,-1,0,0},{0,0,1,-1}};
char a[1010][1010];
int main(){
	int q,r,c;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&r,&c);
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				scanf(" %c",&a[i][j]);
				dis[i][j] = 2e9;
				if(a[i][j] == 'E')	en = {i,j};
				if(a[i][j] == 'S')	st = {i,j};
			}
		}
		dis[en.first][en.second] = 0;
		que.push({en.first,en.second,0});
		while(!que.empty()){
			now = que.front();
			que.pop();
			for(int k=0;k<4;k++){
				int ni = now.i+dir[0][k],nj = now.j+dir[1][k];
				if(ni<1 || nj<1 || ni>r || nj>c)	continue;
				if(a[ni][nj] == '#')				continue;
				if(dis[ni][nj]!=2e9)				continue;
				dis[ni][nj] = now.w+1;
				que.push({ni,nj,now.w+1});
			}
		}
		if(dis[st.first][st.second] == 2e9){
			printf("-1\n");
			continue;
		}
		int ans = 0;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++){
				if(!isdigit(a[i][j]))					continue;
				if(dis[i][j]>dis[st.first][st.second])	continue;
				ans+=a[i][j]-'0';
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}