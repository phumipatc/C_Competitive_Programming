/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[25][25];
double dp[1050000];
int main(){
    long long n,countt;
    scanf("%lld",&n);
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    dp[(1<<n)-1] = 1;
    for(long long i=(1<<n)-1;i>=0;i--){
        if(dp[i] == 0)  continue;
        countt = 0;
        for(long long j=0;j<n;j++)
            if((i & (1<<j)) == 0)
                countt++;
        for(long long j=0;j<n;j++){
            if((i & (1<<j)) == 0)   continue;
            dp[i^(1<<j)] = max(dp[i^(1<<j)],dp[i]*a[countt][j]);
        }
    }
    printf("%.2lf\n",dp[0]/pow(100,n-1));
	return 0;
}
