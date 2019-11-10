/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[110][110],dp[110][110],nextt[110][110];
int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(long long i=0;i<n;i++)
        for(long long j=0;j<m;j++)
            scanf("%lld",&a[i][j]);
    for(long long j=m-1;j>=0;j--){
        for(long long i=0;i<n;i++){
            dp[i][j] = a[i][j];
            if(i == 0){
                if(dp[i][j+1]<=dp[(i-1+n)%n][j+1] && dp[i][j+1]<=dp[(i+1+n)%n][j+1]){
                    dp[i][j]+=dp[i][j+1];
                    nextt[i][j] = 0;
                }else if(dp[(i+1+n)%n][j+1]<=dp[(i-1+n)%n][j+1] && dp[(i+1+n)%n][j+1]<=dp[i][j+1]){
                    dp[i][j]+=dp[(i+1+n)%n][j+1];
                    nextt[i][j] = 1;
                }else if(dp[(i-1+n)%n][j+1]<=dp[i][j+1] && dp[(i-1+n)%n][j+1]<=dp[(i+1+n)%n][j+1]){
                    dp[i][j]+=dp[(i-1+n)%n][j+1];
                    nextt[i][j] = -1;
                }
            }else if(i == n-1){
                if(dp[(i+1+n)%n][j+1]<=dp[(i-1+n)%n][j+1] && dp[(i+1+n)%n][j+1]<=dp[i][j+1]){
                    dp[i][j]+=dp[(i+1+n)%n][j+1];
                    nextt[i][j] = 1;
                }if(dp[(i-1+n)%n][j+1]<=dp[i][j+1] && dp[(i-1+n)%n][j+1]<=dp[(i+1+n)%n][j+1]){
                    dp[i][j]+=dp[(i-1+n)%n][j+1];
                    nextt[i][j] = -1;
                }else if(dp[i][j+1]<=dp[(i-1+n)%n][j+1] && dp[i][j+1]<=dp[(i+1+n)%n][j+1]){
                    dp[i][j]+=dp[i][j+1];
                    nextt[i][j] = 0;
                }
            }else{
                if(dp[(i-1+n)%n][j+1]<=dp[i][j+1] && dp[(i-1+n)%n][j+1]<=dp[(i+1+n)%n][j+1]){
                    dp[i][j]+=dp[(i-1+n)%n][j+1];
                    nextt[i][j] = -1;
                }else if(dp[i][j+1]<=dp[(i-1+n)%n][j+1] && dp[i][j+1]<=dp[(i+1+n)%n][j+1]){
                    dp[i][j]+=dp[i][j+1];
                    nextt[i][j] = 0;
                }else if(dp[(i+1+n)%n][j+1]<=dp[(i-1+n)%n][j+1] && dp[(i+1+n)%n][j+1]<=dp[i][j+1]){
                    dp[i][j]+=dp[(i+1+n)%n][j+1];
                    nextt[i][j] = 1;
                }
            }
        }
    }
    long long ans = 1e9,st;
    for(long long i=0;i<n;i++){
        if(dp[i][0]<ans){
            ans = dp[i][0];
            st = i;
        }
    }
    printf("%lld\n",ans);
    long long now = 0;
    while(now<m){
        printf("%lld ",st+1);
        st = (st+nextt[st][now]+n)%n;
        now++;
    }
	return 0;
}
/*
4 8
7 1 8 10 4 1 -5 -1
4 16 5 3 9 5 -3 -9
2 24 4 6 7 4 0 -2
6 10 3 7 2 11 -7 -4
*/
