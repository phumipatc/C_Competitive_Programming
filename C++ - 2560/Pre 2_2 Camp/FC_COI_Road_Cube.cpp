/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,num;
};
deque < A> deq;
int a[110][10100],dp[110][10100];
int main()
{
    int n,m,k,i,j,ans=0;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(j=1;j<=m;j++)
        dp[n][j]=a[n][j];
    for(i=n-1;i>=1;i--){
        for(j=1;j<=k;j++){
            while(!deq.empty() && dp[i+1][j] >= deq.back().num)
                deq.pop_back();
            deq.push_back({j,dp[i+1][j]});
        }
        for(j=1;j<=m;j++){
            while(!deq.empty() && j+k <= m && dp[i+1][j+k] >= deq.back().num)
                deq.pop_back();
            while(!deq.empty() && deq.front().i < j-k)
                deq.pop_front();
            if(j+k <= m)
                deq.push_back({j+k,dp[i+1][j+k]});
            dp[i][j] = a[i][j] + deq.front().num;
        }
        while(!deq.empty()) deq.pop_back();
    }
    for(i=1;i<=m;i++)
        ans=max(ans,dp[1][i]);
    printf("%d\n",ans);
    return 0;
}
/*

*/
