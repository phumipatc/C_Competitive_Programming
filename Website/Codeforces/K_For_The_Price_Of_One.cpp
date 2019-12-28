/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int dp[200010],a[200010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,n,p,k,num;
    cin >> q;
    while(q--){
        cin >> n >> p >> k;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            if(i<k){
                dp[i] = a[i]+dp[i-1];
                continue;
            }
            dp[i] = min(dp[i-k]+a[i],dp[i-1]+a[i]);
        }
        for(int i=n;i>=0;i--){
            if(dp[i]<=p){
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}