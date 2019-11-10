/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100010];
int main(){
    int q,n,m;
    scanf("%d",&q);
    for(int i=1;i<=100000;i++){
        dp[i] = 1e9;
        for(int j=sqrt(i);j>=1;j--)
            dp[i] = min(dp[i],dp[i-(j*j)]+1);
    }
    while(q--){
        scanf("%d %d",&n,&m);
        printf("%d\n",dp[n]%m);
    }
	return 0;
}
