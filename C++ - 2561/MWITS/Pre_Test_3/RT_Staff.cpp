/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010],dp[1000010];
int main(){
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            dp[i] = 1e9;
        }
        dp[0] = -1;
        for(int i=1;i<=n;i++){
            dp[i] = min(dp[i],dp[i-1]+1);
            if(i+a[i]>n)    continue;
            dp[i+a[i]] = min(dp[i+a[i]],dp[i]+1);
        }
        printf("%d\n",dp[n]);
    }
	return 0;
}
