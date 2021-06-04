/*
	Task	: underground
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 23 May 2021 [14:24]
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
const int N = 50;
int a[N][N];
LL dis[N][N][N][N];
struct A{
	int i,j,w;
	bool operator < (const A&o) const{
		return w>o.w;
	}
}now;
priority_queue<A > heap;
int dig_paths(int r, int c,
	      std::vector<std::vector<int>>& A)
{
	rep(i,1,r)
		rep(j,1,c)
			a[i][j] = A[i-1][j-1];
	rep(i,1,r){
		rep(j,1,c){
			rep(k,1,r)
				rep(l,1,c)
					dis[i][j][k][l] = 1e9;
			dis[i][j][i][j] = a[i][j];
			heap.push({i,j,a[i][j]});
			while(!heap.empty()){
				now = heap.top();
				heap.pop();
				rep(x,0,3){
					int ni = now.i+dir4[0][x],nj = now.j+dir4[1][x];
					if(ni<1 || nj<1 || ni>r || nj>c)		continue;
					if(dis[i][j][ni][nj]<=now.w+a[ni][nj])	continue;
					dis[i][j][ni][nj] = now.w+a[ni][nj];
					heap.push({ni,nj,now.w+a[ni][nj]});
				}
			}
		}
	}
	LL minn = 1e9;
	rep(i,1,r){
		rep(j,1,c){
			rep(k,1,r){
				rep(l,1,c){
					minn = min(minn,dis[1][1][i][j] + dis[r][1][i][j] + dis[1][c][k][j] + dis[r][c][k][j] - (2*a[i][j]) - (2*a[k][j]) + dis[i][j][k][l]);
				}
			}
		}
	}
	return minn;
}