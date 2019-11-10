/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long dp[4100],temp[4100],a[2010];
int main(){
    long long n,countt;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        countt = 1;
        while(a[i] == a[i+1])   countt++,i++;
        memset(temp,0,sizeof temp);
        temp[a[i]]+=countt;
        for(long long j=0;j<=4096;j++){
            if(!dp[j])  continue;
            temp[j^a[i]]+=dp[j]*countt,temp[j^a[i]]%=MOD;
            // printf("%lld %lld %lld\n",j,j^a[i],dp[j]);
        }
        for(long long j=0;j<=4096;j++)
            dp[j]+=temp[j],dp[j]%=MOD;
    }
    long long num;
    scanf("%lld",&num);
    printf("%lld\n",dp[num]);
	return 0;
}
