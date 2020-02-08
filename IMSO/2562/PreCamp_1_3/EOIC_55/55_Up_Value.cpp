/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10010],dp[10010];
int main(){
    int q,n,k,maxx;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            maxx = 0;
            for(int j=1;j<=k && i-j>=0;j++){
                maxx = max(maxx,a[i-j+1]);
                dp[i] = max(dp[i],dp[i-j]+(maxx*j));
            }
            // printf("%d\n",dp[i]);
        }
        printf("%d\n",dp[n]);
        memset(dp,0,sizeof dp);
    }
	return 0;
}