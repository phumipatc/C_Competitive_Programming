/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int main()
{
    int m,s,e,a,b,i,j,k;
    scanf("%d %d %d",&m,&s,&e);
    for(i=1;i<=60;i++){
        for(j=1;j<=60;j++){
            dp[i][j]=1e9;
        }
    }
    while(m--){
        scanf("%d %d",&a,&b);
        dp[a][b]=dp[b][a]=1;
    }
    for(k=1;k<=60;k++)
        for(i=1;i<=60;i++)
            for(j=1;j<=60;j++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    printf("%d\n",dp[s][e]);
    return 0;
}
