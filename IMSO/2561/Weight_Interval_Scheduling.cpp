/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int st,en,w;
	bool operator < (const A&o) const{
		if(en!=o.en)	return en<o.en;
		else			return st>o.st;
	}
};
A a[1010];
int bs[1010],dp[1010];
int main(){
	// freopen("0_in.txt","r",stdin);
	// freopen("0_out.txt","w",stdout);
	int n,idx;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d %d",&a[i].st,&a[i].en,&a[i].w);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		bs[i] = a[i].en;
	for(int i=1;i<=n;i++){
		idx = lower_bound(bs+1,bs+n+1,a[i].st)-bs;
		dp[i] = max(dp[i-1],a[i].w+dp[idx-1]);
		printf("%d %d\n",idx,dp[i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}
