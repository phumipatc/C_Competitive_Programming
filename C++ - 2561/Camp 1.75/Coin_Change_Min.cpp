/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000010];
int main(){
    int n,m,num;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
        dp[i] = 1e9;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        for(int i=num;i<=m;i++){
            if(dp[i-num] != 1e9)
                dp[i] = min(dp[i-num]+1,dp[i]);
        }
    }
    if(dp[m] != 1e9)    printf("%d\n",dp[m]);
    else                printf("0\n");
	return 0;
}
