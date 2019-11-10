/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,now;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&now);
		if(i<3)	continue;
		dp[i] = max(dp[i-1],now+dp[i-3]);
	}
	printf("%d\n",dp[n]);
	return 0;
}
