/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[1000];
int main(){
    long long n,en;
    cin >> n;
    en = (n*(1+n))/2;
    if(en%2){
        printf("0\n");
        return 0;
    }
    en/=2;
    dp[0] = 1;
    for(long long i=1;i<=n;i++)
        for(long long j=en;j>=i;j--)
            dp[j]+=dp[j-i];
    printf("%lld\n",dp[en]/2);
	return 0;
}
