/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 10001
using namespace std;
int dp[1100];
int main(){
    int n;
    scanf("%d",&n);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
            dp[i]%=MOD;
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
