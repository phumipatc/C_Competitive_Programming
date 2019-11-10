/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100010][32];
int main(){
    long long n,q,temp,a,b,ans = 0;
    cin >> n >> q;
    for(long long i=1;i<=n;i++){
        cin >> temp;
        for(long long j=0;j<32;j++)
            dp[i][j] = ((1<<j)&temp);
    }
    for(long long i=1;i<=n;i++){
        for(long long j=0;j<32;j++){
            dp[i][j]+=dp[i-1][j];
        }
    }
    while(q--){
        cin >> a >> b;
        ans = 0;
        for(long long i=0;i<32;i++){
            if(dp[b][i]-dp[a-1][i]){
                ans|=(1<<i);
            }
        }
        cout << ans << endl;
    }
	return 0;
}
