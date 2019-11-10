/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int temp[30][30],dp[30][30];
int main(){
    int q,r,c,k,p,ans;
    scanf("%d",&q);
    while(q--){
        ans = 0;
        scanf("%d %d %d %d",&r,&c,&k,&p);
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                dp[i][j] = 1;
        k--;
        while(k--){
            for(int i=1;i<=r;i++)
                for(int j=1;j<=c;j++)
                    temp[i][j] = (dp[i][j]+dp[i-1][j]+dp[i][j-1]+dp[i+1][j]+dp[i][j+1])%p;
            for(int i=1;i<=r;i++)
                for(int j=1;j<=c;j++)
                    dp[i][j] = temp[i][j];
        }
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                ans+=dp[i][j],ans%=p;
        printf("%d\n",ans);
        memset(dp,0,sizeof dp);
        memset(temp,0,sizeof temp);
    }
	return 0;
}
