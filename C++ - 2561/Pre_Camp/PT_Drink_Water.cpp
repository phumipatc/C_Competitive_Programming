/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[25][25],dp[1050000];
int main(){
    int q,n,kk,now,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&kk);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<(1<<n);i++)
            dp[i] = 1e9;
        dp[(1<<n)-1] = 0;
        for(int i=(1<<n)-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if((i & (1<<j)) == 0)   continue;
                for(int k=0;k<n;k++){
                    if((i & (1<<k)) == 0)   continue;
                    if(j == k)              continue;
                    dp[i^(1<<j)] = min(dp[i^(1<<j)],dp[i]+a[j][k]);
                }
            }
        }
        ans = 1e9;
        for(int i=0;i<(1<<n);i++){
            now = 0;
            for(int j=0;j<n;j++){
                if(i&(1<<j))
                    now++;
            }
            if(now<=kk) ans = min(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
	return 0;
}
