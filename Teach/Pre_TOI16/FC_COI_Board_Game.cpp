/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Sliding window
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
struct A{
	int i,j,w,bit;
};
queue<A > que;
int dis[510][510][10];
char a[510][510];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m;
	PII st,en;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			if(a[i][j] == 'S')		st = {i,j};
			else if(a[i][j] == 'E')	en = {i,j};
			else if(a[i][j] == 'j')	a[i][j] = 'a';
			else if(a[i][j] == 'p')	a[i][j] = 'c';
			else if(a[i][j] == 'J')	a[i][j] = 'A';
			else if(a[i][j] == 'P')	a[i][j] = 'C';
			for(int k=0;k<(1<<3);k++)
				dis[i][j][k] = 1e9;
		}
	}
	que.push({st.first,st.second,0,0});
	dis[st.first][st.second][0] = 0;
	while(!que.empty()){
		auto now = que.front();
		que.pop();
		// printf("%d %d %d %d\n",now.i,now.j,now.w,now.bit);
		if(make_pair(now.i,now.j) == en){
			cout << now.w;
			return 0;
		}
		for(int k=0;k<4;k++){
			int ni = now.i+dir4[0][k];
			int nj = now.j+dir4[1][k];
			int nb = now.bit;
			if(ni<1 || nj<1 || ni>n || nj>m)	continue;
			if(a[ni][nj] == '#')				continue;
			if(a[ni][nj]!='S' && a[ni][nj]!='E' && isupper(a[ni][nj]) && (now.bit&(1<<(a[ni][nj]-'A'))) == 0)	continue;
			if(islower(a[ni][nj]))				nb|=1<<(a[ni][nj]-'a');
			if(dis[ni][nj][nb]<=now.w+1)		continue;
			// printf("Next: %d %d %d %d\n",ni,nj,now.bit,(1<<(a[ni][nj]-'A')));
			dis[ni][nj][nb] = now.w+1;
			que.push({ni,nj,now.w+1,nb});
		}
	}
	cout << "-1\n";
	return 0;
}