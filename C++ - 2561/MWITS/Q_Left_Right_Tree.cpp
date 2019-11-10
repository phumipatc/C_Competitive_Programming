/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9999991
using namespace std;
long long dp[130][130];
long long tree(long long l,long long r){
    if(l == 0 || r == 0)    return dp[l][r] = 1;
    if(dp[l][r])            return dp[l][r];
    dp[l][r]+=tree(l-1,r);  dp[l][r]%=MOD;
    dp[l][r]+=tree(l,r-1);  dp[l][r]%=MOD;
    for(long long i=0;i<l;i++){
        for(long long j=0;j<r;j++){
            dp[l][r]+=tree(i,j)*tree(l-i-1,r-j-1);
            dp[l][r]%=MOD;
        }
    }
    return dp[l][r];
}
int main(){
    long long q,n,m;
    cin >> q;
    while(q--){
        cin >> n >> m;
        cout << tree(n,m) << endl;
    }
	return 0;
}
