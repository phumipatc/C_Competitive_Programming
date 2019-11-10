/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    //1
    if(a[i] == b[j])
        dp[i][j] = dp[i-1][j-1]+1;
    else
        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    //2
    if(a[i] == b[j])
        dp[i][j] = dp[i-1][j-1]+1;
    dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
    return 0;
}
