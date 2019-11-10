/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010],dp[1000010],maxx[1000010];
int main(){
    int n,minn = 1e9,ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[i] = max(dp[i-1],a[i]-minn);
        ans = max(ans,dp[i]);
        minn = min(minn,a[i]);
    }
    for(int i=n;i>=1;i--)
        maxx[i] = max(maxx[i+1],a[i]);
    for(int i=3;i<n;i++){
        if(dp[i-1]-a[i]+maxx[i+1]>ans)
            ans = dp[i-1]-a[i]+maxx[i+1];
    }
    printf("%d\n",ans);
	return 0;
}
