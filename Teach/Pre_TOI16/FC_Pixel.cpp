/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Divide & Conquer
	Status	: 
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
char str[520];
int qs[520][520],dp[520][520][12];
int sum;
int divide(PII a,PII b,int logn){
	if(a == b)	return 0;
	if(dp[a.first][a.second][logn]!=-1)	return dp[a.first][a.second][logn];
	int mi = (a.first+b.first)/2;
	int mj = (a.second+b.second)/2;
	int qs1 = qs[mi][mj] - qs[mi][a.second-1] - qs[a.first-1][mj] + qs[a.first-1][a.second-1];
	int qs2 = qs[mi][b.second] - qs[a.first-1][b.second] - qs[mi][mj] + qs[a.first-1][mj];
	int qs3 = qs[b.first][mj] - qs[mi][mj] - qs[b.first][a.second-1] + qs[mi][a.second-1];
	int qs4 = qs[b.first][b.second] - qs[mi][b.second] - qs[b.first][mj] + qs[mi][mj];
	int sizee = (b.first-a.first+1)*(b.second-a.second+1)/4;
	int minn = 1e9;
	//up-left
    minn=min(minn,divide({mi+1,a.second},{b.first,mj},logn-1)+divide({mi+1,mj+1},{b.first,b.second},logn-1)+qs1+(sizee-qs2));
    minn=min(minn,divide({a.first,mj+1},{mi,b.second},logn-1)+divide({mi+1,mj+1},{b.first,b.second},logn-1)+qs1+(sizee-qs3));
    minn=min(minn,divide({a.first,mj+1},{mi,b.second},logn-1)+divide({mi+1,a.second},{b.first,mj},logn-1)+qs1+(sizee-qs4));
    //up-right
    minn=min(minn,divide({mi+1,a.second},{b.first,mj},logn-1)+divide({mi+1,mj+1},{b.first,b.second},logn-1)+qs2+(sizee-qs1));
    minn=min(minn,divide({a.first,a.second},{mi,mj},logn-1)+divide({mi+1,mj+1},{b.first,b.second},logn-1)+qs2+(sizee-qs3));
    minn=min(minn,divide({a.first,a.second},{mi,mj},logn-1)+divide({mi+1,a.second},{b.first,mj},logn-1)+qs2+(sizee-qs4));
    //down-left
    minn=min(minn,divide({a.first,mj+1},{mi,b.second},logn-1)+divide({mi+1,mj+1},{b.first,b.second},logn-1)+qs3+(sizee-qs1));
    minn=min(minn,divide({a.first,a.second},{mi,mj},logn-1)+divide({mi+1,mj+1},{b.first,b.second},logn-1)+qs3+(sizee-qs2));
    minn=min(minn,divide({a.first,a.second},{mi,mj},logn-1)+divide({a.first,mj+1},{mi,b.second},logn-1)+qs3+(sizee-qs4));
    //down-right
    minn=min(minn,divide({a.first,mj+1},{mi,b.second},logn-1)+divide({mi+1,a.second},{b.first,mj},logn-1)+qs4+(sizee-qs1));
    minn=min(minn,divide({a.first,a.second},{mi,mj},logn-1)+divide({mi+1,a.second},{b.first,mj},logn-1)+qs4+(sizee-qs2));
    minn=min(minn,divide({a.first,a.second},{mi,mj},logn-1)+divide({a.first,mj+1},{mi,b.second},logn-1)+qs4+(sizee-qs3));
	
	return dp[a.first][a.second][logn] = minn;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf(" %s",str+1);
		for(int j=1;j<=n;j++)
			qs[i][j] = (str[j]-'0')+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
	}
	memset(dp,-1,sizeof dp);
	printf("%d\n",divide({1,1},{n,n},log2(n)));
	return 0;
}