/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 2009;
int v[22][22],a[110],dp[110][110][22];
int n;
int divide(int l,int r,int res){
    if(l == r){
        if(res == a[l])     return 1;
        else                return 0;
    }
    if(dp[l][r][res]!=-1)   return dp[l][r][res];
    for(int i=0;i<n;i++)    dp[l][r][i] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=l;k<r;k++){
                // printf("%d %d %d %d %d\n",l,r,v[i][j],divide(l,k,i),divide(k+1,r,j));
                dp[l][r][v[i][j]]+=divide(l,k,i)*divide(k+1,r,j);
                dp[l][r][v[i][j]]%=MOD;
            }
        }
    }
    return dp[l][r][res];
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> v[i][j];
    int k;
    cin >> k;
    for(int i=1;i<=k;i++)
        cin >> a[i];
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++)
        cout << divide(1,k,i) << "\n";
    return 0;
}