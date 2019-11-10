/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000010][2];
char str[1000010];
int main(){
    int n;
    scanf("%d %s",&n,str+1);
    for(int i=1;i<=n;i++){
        if(str[i] == 'A'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][1])+1;
        }else{
			dp[i][0] = min(dp[i-1][0],dp[i-1][1])+1;
            dp[i][1] = dp[i-1][1];
        }
    }
    printf("%d\n",dp[n][0]);
    return 0;
}
