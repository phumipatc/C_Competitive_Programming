/*
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int h[100100],dp[100100];
int main()
{
    int q,n,k,i,idx,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)
            scanf("%d",&h[i]);
        dp[1]=1;
        for(i=2;i<=n;i++){
            dp[i]=dp[i-1];
            int idx=lower_bound(h+1,h+n+1,h[i]-k)-h-1;
            dp[i]-=dp[idx];
            dp[i]+=dp[i-1];
            dp[i]%=95959;
        }
        printf("%d\n",(dp[n]-dp[n-1]+95959)%95959);
        memset(h,0,sizeof h);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
