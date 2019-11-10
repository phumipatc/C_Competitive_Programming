/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[5];
int dp[100001];
int main(){
    int n,k,ans = 0;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> str;
        if(!strcmp(str,"UR"))  dp[i]++;
        dp[i]+=dp[i-1];
    }
    for(int i=1;i<=n-k+1;i++)
        ans = max(ans,dp[i+k-1]-dp[i-1]);
    cout << ans << endl;
    return 0;
}
