/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int dp[1010][1010];
int main(){
    int r,c,ans = 0;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        scanf(" %s",a[i]+1);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j] == '#')  continue;
            dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
            ans = max(ans,dp[i][j]);
        }
    }
    printf("%d\n",ans);
	return 0;
}
