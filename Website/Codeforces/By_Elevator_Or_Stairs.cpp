/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
priority_queue<int > heap;
int dp[200010],a[200010],b[200010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,c;
    cin >> n >> c;
    for(int i=1;i<n;i++)
        cin >> a[i];
    for(int i=1;i<n;i++)
        cin >> b[i],b[i]+=b[i-1];
    for(int i=1;i<=n;i++){
        dp[i] = a[i-1]+dp[i-1];
        if(!heap.empty())   dp[i] = min(dp[i],c+b[i-1]-heap.top());
        heap.push(-(dp[i]-b[i-1]));
        printf("%d ",dp[i]);
    }
    return 0;
}