/*
	Task	: underground
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 23 May 2021 [13:41]
	Algo	: 
	Status	: 
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define repr(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
#include "underground.h"
const int N = 510;
int a[N][N];
int mark[N][N],mark2[N][N];
int sum = 0,r,c,minn = 1e9;
void dfs2(int i,int j){
	mark2[i][j] = 1;
	if(!mark[i][j])	sum+=a[i][j];
	if(i == 1 && j == c){
		minn = min(minn,sum);
		// printf("%d\n",minn);
		if(!mark[i][j])	sum-=a[i][j];
		mark2[i][j] = 0;
		return ;
	}
	for(int k=0;k<4;k++){
		int ni = i+dir4[0][k],nj = j+dir4[1][k];
		if(ni<1 || nj<1 || ni>r || nj>c)	continue;
		if(mark2[ni][nj])					continue;
		dfs2(ni,nj);
	}
	mark2[i][j] = 0;
	if(!mark[i][j])	sum-=a[i][j];
}
void dfs(int i,int j){
	mark[i][j] = 1;
	sum+=a[i][j];
	if(i == r && j == c){
		// printf("%d\n",sum);
		dfs2(r,1);
		mark[i][j] = 0;
		sum-=a[i][j];
		return ;
	}
	for(int k=0;k<4;k++){
		int ni = i+dir4[0][k],nj = j+dir4[1][k];
		if(ni<1 || nj<1 || ni>r || nj>c)	continue;
		if(mark[ni][nj])					continue;
		dfs(ni,nj);
	}
	mark[i][j] = 0;
	sum-=a[i][j];
}
int dig_paths(int R, int C,
	      std::vector<std::vector<int>>& A)
{
	r = R,c = C;
	rep(i,0,R-1)
		rep(j,0,C-1)
			a[i+1][j+1] = A[i][j];
	dfs(1,1);
	return minn;
}
