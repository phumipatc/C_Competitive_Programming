/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[50],swift[50];
long long GCD(long long a,long long b){
    if(a%b == 0)    return b;
    else            return GCD(b,a%b);
}
int main(){
    long long a,b,num,ans = 0;
    dp[1] = 1;
    for(long long i=2;i<=42;i++){
        dp[i] = dp[i-1]*(i/GCD(dp[i-1],i));
        // printf("%lld : %lld\n",i,dp[i]);
    }
    swift[2] = 1;
    for(long long i=3;i<=41;i++){
        for(long long j=2;j<=41;j++){
            if(i%j == 0)    continue;
            swift[i] = swift[j]+1;
            break;
        }
    }
    scanf("%lld %lld",&a,&b);
    for(long long i=1;i<=40;i++){
        num = (b/dp[i])-(b/dp[i+1]);
        ans+=num*(swift[i+1]+1);
        // printf("%lld %lld %lld\n",num,swift[i+1]+1,ans);
        num = ((a-1)/dp[i])-((a-1)/dp[i+1]);
        ans-=num*(swift[i+1]+1);
        // printf("%lld %lld %lld\n",num,swift[i+1]+1,ans);
    }
    printf("%lld\n",ans);
	return 0;
}
