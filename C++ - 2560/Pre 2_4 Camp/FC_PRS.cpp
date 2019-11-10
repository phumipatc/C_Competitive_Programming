/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 2553
using namespace std;
char str[1000005];
int dp[1000005][7];
int main(){
    int n,now;
    cin >> n >> str+1;
    for(int i=1;i<=n;i++){
        dp[i][1] = (dp[i-1][3] + dp[i-1][4] + dp[i-1][5] + dp[i-1][6])%MOD;
        dp[i][2] =  dp[i-1][1];
        dp[i][3] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][5] + dp[i-1][6])%MOD;
        dp[i][4] =  dp[i-1][3];
        dp[i][5] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4])%MOD;
        dp[i][6] =  dp[i-1][5];
        if(str[i]=='P'){
            if(now==1)  now=2;
            else        now=1;
        }else if(str[i]=='R'){
            if(now==1)      dp[i][2]++;
            else if(now!=2) dp[i][1]++;
            if(now==3)      now=4;
            else            now=3;
        }
        else if(str[i]=='S'){
            if(now==1)      dp[i][2]++;
            else if(now!=2) dp[i][1]++;
            if(now==3)      dp[i][4]++;
            else if(now!=4) dp[i][3]++;
            if(now==5)      now=6;
            else            now=5;
        }
    }
    int ans=1;
    for(int i=1;i<=6;i++){
        ans+=dp[n][i];
        ans%=MOD;
    }
    cout << ans << endl;
    return 0;
}
