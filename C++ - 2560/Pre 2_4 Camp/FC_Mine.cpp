/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1010][1010],qs[1010][1010],dp[1010][1010],temp[1010][1010];
long long ans[4][1010][1010];
struct A{
    long long i,j,v;
};
deque < A> deq;
int main(){
    long long n,k,i,j,maxx=0;
    scanf("%lld %lld",&n,&k);
    for(int x=1;x<=3;x++){
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%lld",&a[i][j]);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                qs[i][j]=a[i][j]+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        for(i=1;i<=n-k+1;i++)
            for(j=1;j<=n-k+1;j++)
                dp[i][j]=qs[i+k-1][j+k-1]-qs[i-1][j+k-1]-qs[i+k-1][j-1]+qs[i-1][j-1];
        for(i=1;i<=n-k+1;i++){
            for(j=n-k+1;j>=1;j--){
                while(!deq.empty() && deq.front().j>=j+k)         deq.pop_front();
                while(!deq.empty() && deq.back().v<dp[i][j])    deq.pop_back();
                deq.push_back({i,j,dp[i][j]});
                temp[i][j]=deq.front().v;
            }
            while(!deq.empty())   deq.pop_front();
        }
        for(j=1;j<=n-k+1;j++){
            for(i=n-k+1;i>=1;i--){
                while(!deq.empty() && deq.back().v<temp[i][j])  deq.pop_back();
                while(!deq.empty() && deq.front().i>=i+k)       deq.pop_front();
                deq.push_back({i,j,temp[i][j]});
                ans[x][i][j] = deq.front().v;
            }
            while(!deq.empty())   deq.pop_front();
        }
        while(!deq.empty())   deq.pop_front();
    }
    while(!deq.empty()) deq.pop_front();
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            maxx=max(maxx,ans[1][i][j]+ans[2][i][j]+ans[3][i][j]);
    printf("%lld\n",maxx);
}
