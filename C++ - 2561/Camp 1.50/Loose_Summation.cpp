/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000003
using namespace std;
int dp[2010];
int main(){
    int q,n;
    dp[0] = 1;
    for(int i=1;i<=2000;i++)
        for(int j=2000;j>=i;j--)
            dp[j] = (dp[j]+dp[j-i])%MOD;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
	return 0;
}
