/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[1<<21],a[20];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,num = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        num*=2;
        num+=a[i];
    }
    for(int i=0;i<1<<n;i++)
        dp[i] = 1e9;
    dp[num] = 0;
    for(int i=0;i<n;i++){
        num = 1<<i;
        if(i>0)     num|=1<<(i-1);
        if(i<n-1)   num|=1<<(i+1);
        for(int j=0;j<1<<n;j++){
            if(dp[j] == 1e9)    continue;
            dp[j^num] = min(dp[j^num],dp[j]+1);
        }
    }
    if(dp[0] == 1e9)    dp[0] = -1;
    printf("%d\n",dp[0]);
    return 0;
}