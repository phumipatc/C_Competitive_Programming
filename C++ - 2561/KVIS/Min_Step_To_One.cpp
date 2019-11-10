/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100];
int main(){
    int q,p;
    scanf("%d",&q);
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for(int i=4;i<=1000000;i++){
        dp[i] = 1e9;
        if(i%2 == 0)    dp[i] = min(dp[i],dp[i/2]+1);
        if(i%3 == 0)    dp[i] = min(dp[i],dp[i/3]+1);
        dp[i] = min(dp[i],dp[i-1]+1);
    }
    while(q--){
        scanf("%d",&p);
        printf("%d\n",dp[p]);
    }
	return 0;
}
