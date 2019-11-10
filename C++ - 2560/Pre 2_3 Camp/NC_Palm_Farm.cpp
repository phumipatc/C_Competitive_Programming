/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[111][111][2],mic[111][111][6010],mark[111][111][6010];
int main(){
    long long n,m,i,j,ans=0,now,k;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%lld",&now);
            if(now==0)  continue;
            while(now%2==0)
                dp[i][j][0]++,now/=2;
            while(now%7==0)
                dp[i][j][1]++,now/=7;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            mic[i][j][dp[i][j][0]]=dp[i][j][1];
            mark[i][j][dp[i][j][0]]=1;
            for(k=0;k<=6000;k++){
                if(mark[i-1][j][k]){
                    mic[i][j][k+dp[i][j][0]]=max(mic[i][j][k+dp[i][j][0]],mic[i-1][j][k]+dp[i][j][1]);
                    mark[i][j][k+dp[i][j][0]]=1;
                }
                if(mark[i][j-1][k]){
                    mic[i][j][k+dp[i][j][0]]=max(mic[i][j][k+dp[i][j][0]],mic[i][j-1][k]+dp[i][j][1]);
                    mark[i][j][k+dp[i][j][0]]=1;
                }
            }
        }
    }
    for(i=0;i<=6000;i++){
        ans=max(ans,min(i,mic[n][m][i]));
    }
    printf("%lld\n",ans);
    return 0;
}
