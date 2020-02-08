/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int v,w;
};
vector<A > g[3010];
int p[3010],dp[3010];
int mem(int u,int k){
	if(dp[u]!=-1)	return dp[u];
	dp[u] = 0;
	// printf("%d ",u);
	for(auto x:g[u]){
		if(x.w>k)	continue;
		dp[u] = max(dp[u],mem(x.v,k));
	}
	dp[u]++;
	return dp[u];
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	m++;
	for(int i=0;i<n;i++)
		scanf("%d",&p[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j)		continue;
			if(p[j]<=p[i])	continue;
			g[i].push_back({j,(j+n-i)%n});
		}
	}
	int l = 0,r = n,mid,maxx;
	while(l<r){
		mid = (l+r)/2,maxx = 0;
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++)
			maxx = max(maxx,mem(i,mid));
		// printf("%d %d %d:",l,r,mid);
		// for(int i=0;i<n;i++)
			// printf("%d ",dp[i]);
		// printf("\n");
		if(maxx>=m)	r = mid;
		else		l = mid+1;
	}
	printf("%d\n",l);
	return 0;
}