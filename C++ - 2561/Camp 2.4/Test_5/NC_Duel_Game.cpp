/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],dp[100005][2];
long long duel(long long now,long long player){
    if(now>n)               return 0;
    if(dp[now][player]!=-1) return dp[now][player];
    long long ans = 0;
    if(player == 0)
        ans = max(a[now]+duel(now+1,1),max(a[now]+a[now+1]+duel(now+2,1),a[now]+a[now+1]+a[now+2]+duel(now+3,1)));
    if(player == 1)
        ans = min(duel(now+1,0),min(duel(now+2,0),duel(now+3,0)));
    return dp[now][player] = ans;
}
int main(){
    long long q;
    cin >> q;
    while(q--){
        cin >> n;
        memset(dp,-1,sizeof dp);
        a[n+1] = a[n+2] = a[n+3] =0;
        for(long long i=1;i<=n;i++)
            cin >> a[i];
        cout << duel(1,0) << endl;
    }
    return 0;
}
