/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int  countt[110][110][2],dp[110][110][6010],mark[110][110][6010];
int main(){
    int  n,m,ans = 0,now,k,l,r,mid,sum;
    scanf("%d %d",&n,&m);
    for(int  i=1;i<=n;i++){
        for(int  j=1;j<=m;j++){
            scanf("%d",&now);
            if(now == 0)    continue;
            while(now%2==0) countt[i][j][0]++,now/=2;
            while(now%7==0) countt[i][j][1]++,now/=7;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j][countt[i][j][0]] = countt[i][j][1];
            mark[i][j][countt[i][j][0]] = 1;
            for(k=0;k<=6000;k++){
                if(mark[i-1][j][k]){
                    dp[i][j][k+countt[i][j][0]] = max(dp[i][j][k+countt[i][j][0]],dp[i-1][j][k]+countt[i][j][1]);
                    mark[i][j][k+countt[i][j][0]] = 1;
                }
                if(mark[i][j-1][k]){
                    dp[i][j][k+countt[i][j][0]] = max(dp[i][j][k+countt[i][j][0]],dp[i][j-1][k]+countt[i][j][1]);
                    mark[i][j][k+countt[i][j][0]] = 1;
                }
            }
        }
    }
    for(int  i=0;i<=6000;i++){
        ans = max(ans,min(i,dp[n][m][i]));
    }
    printf("%d\n",ans);
    return 0;
}
