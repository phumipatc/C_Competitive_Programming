/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 100003
using namespace std;
int dp[100010];
int main(){
    int q,n;
    dp[0] = 1;
    for(int i=1;i<=100000;i++){
        dp[i]+=dp[i-1];
        if(i>=4)    dp[i]+=dp[i-4];
        dp[i]%=MOD;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
	return 0;
}
