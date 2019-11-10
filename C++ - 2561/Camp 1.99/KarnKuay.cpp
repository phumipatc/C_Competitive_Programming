/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100010];
int main(){
    int n,num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        if(i<3) continue;
        dp[i] = max(dp[i-1],num+dp[i-3]);
    }
    printf("%d\n",dp[n]);
	return 0;
}
