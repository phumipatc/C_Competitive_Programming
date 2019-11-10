/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define INF 1e6
using namespace std;
int dp[12][10005],a[12];
int play(int n,int k){
    if(k<0)             return INF;
    if(dp[n][k]!=-1)    return dp[n][k];
    if(k == 0 && n != 0)return INF;
    if(n==0 && k==0)    return 0;
    if(n==0)            return INF;
    int minn=INF;
    for(int i=1;i<=sqrt(k)+1;i++){
        minn=min(minn,play(n-1,k-i*i)+(a[n]-i)*(a[n]-i));

    }
    return dp[n][k]=minn;
}
int main(){
    int n,b;
    cin >> n >> b;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,-1,sizeof dp);
    printf("%d\n",(play(n,b)!= INF) ? play(n,b) :-1);
    return 0;
}
