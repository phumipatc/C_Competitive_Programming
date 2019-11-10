/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[5010],dp[5010];
int main(){
    int n,k,maxx;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        maxx = 0,dp[i] = 1e9;
        for(int j=1;j<=k && i-j>=0;j++){
            maxx = max(maxx,a[i-j+1]);
            dp[i] = min(dp[i],dp[i-j]+maxx);
        }
    }
    printf("%d\n",dp[n]);
	return 0;
}
