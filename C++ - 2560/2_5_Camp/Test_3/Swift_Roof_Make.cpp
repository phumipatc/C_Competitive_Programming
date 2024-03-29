/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int cow[5005],price[100005],dp[5005];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> cow[i];
    sort(cow+1,cow+n+1);
    for(int i=1;i<=m;i++)
        cin >> price[i];
    for(int i=m-1;i>=1;i--)
        price[i] = min(price[i],price[i+1]);
    for(int i=1;i<=n;i++)   dp[i] = 1e9;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            dp[i] = min(dp[i],price[cow[i]-cow[j]+1]+dp[j-1]);
    printf("%d\n",dp[n]);
    return 0;
}
