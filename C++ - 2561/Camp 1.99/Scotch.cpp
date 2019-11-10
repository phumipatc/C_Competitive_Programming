/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[5][5],mark[5][5];
long long decr(long long x,long long y){
    return ((long long )ceil((double )x/y))%2;
}
int main(){
    long long n,a,b,ans = 0;
    scanf("%lld %lld %lld",&n,&a,&b);
    for(long long i=1;i<=n;i++){
        if(!mark[decr(i,a)][decr(i,b)]){
            mark[decr(i,a)][decr(i,b)] = 1;
            for(long long j=1;j<=n;j++){
                if(decr(i,a) == decr(j,a) || decr(i,b) == decr(j,b))
                    dp[decr(i,a)][decr(i,b)]++;
            }
        }
        ans+=dp[decr(i,a)][decr(i,b)];
    }
    printf("%lld\n",ans);
	return 0;
}
