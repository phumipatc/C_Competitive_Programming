/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2000010];
int main(){
    int n,m,k,temp;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m+k;i++) dp[i] = 1e9;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        for(int j=temp;j<=m+k;j++)
            dp[j] = min(dp[j],dp[j-temp]+1);
    }
    int minn = 1e9,ans;
    for(int i=m;i<=m+k;i++){
        if(minn>dp[i]){
            minn = dp[i];
            ans = i-m;
        }
    }
    if(minn == 1e9) printf("-1\n");
    else            printf("%d\n%d\n",minn,ans);
	return 0;
}
