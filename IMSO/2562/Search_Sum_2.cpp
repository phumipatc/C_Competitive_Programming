/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef long long LL;
int a[1010],dp[1010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,k;
    cin >> n >> k;
    fill(dp,dp+1005,INF);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
        for(int j=1;j<=i;j++)
            dp[i-j+1] = min(dp[i-j+1],a[i]-a[j-1]);
    }
    int num;
    while(k--){
        cin >> num;
        cout << upper_bound(dp+1,dp+n+1,num)-dp-1 << "\n";
    }
    return 0;
}