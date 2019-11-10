/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[100010];
int main(){
    long long n,m,temp,ans1 = 0,ans2 = 0;
    for(long long i=2;i<=100000;i++)
        dp[i] = 1e9;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&temp);
        if(dp[temp]!=1e9)   ans1++,ans2+=dp[temp];
        else{
            for(long long j=temp;j<=100000;j+=temp)
                dp[j] = min(dp[j],dp[j/temp]+1);
        }
    }
    printf("%lld ",ans1);
    if(m == 2)  printf("%lld\n",ans2);
	return 0;
}
