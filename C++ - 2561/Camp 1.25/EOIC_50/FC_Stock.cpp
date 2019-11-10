/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],maxx[1000100],dp[1000100];
int main(){
    int n,q;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        maxx[i] = max(0,a[i]-a[i-1]);
        dp[i] = dp[i-1]+maxx[i];
    }
    int u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&u,&v);
        printf("%d\n",dp[v]-dp[u]);
    }
	return 0;
}
