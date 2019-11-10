/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int maxx[1000010],dp[1000010],a[1000010];
int main(){
    int n,minn = 1e9,ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i] = max(dp[i-1],a[i]-minn);
        minn = min(minn,a[i]);
        ans = max(ans,dp[i]);
    }
    for(int i=n;i>=1;i--)
        maxx[i] = max(maxx[i+1],a[i]);
    for(int i=3;i<n;i++)
        ans = max(ans,dp[i-1]+maxx[i+1]-a[i]);
    printf("%d\n",ans);
	return 0;
}
