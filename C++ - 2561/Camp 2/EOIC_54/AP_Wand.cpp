/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100010];
vector<int > g[100010];
int main(){
    int n,k,t,u,v,pos = 0;
    cin >> n >> k >> t;
    while(k--){
        cin >> u >> v;
        u++,v++;
        g[u].push_back(v);
    }
    for(int i=2;i<=n+1;i++) dp[i] = 1e9;
    for(int i=1;i<=n+1;i++){
        dp[i] = min(dp[i],dp[i-1]+1);
        for(auto x:g[i])
            dp[x] = min(dp[x],dp[i]+1);
    }
    printf("%d\n",dp[n+1]);
    if(dp[n+1]<=t)  printf("1\n");
    else{
        printf("0 ");
        for(int i=n;i>=1;i--){
            if(dp[i]<=t){
                printf("%d\n",i-1);
                break;
            }
        }
    }
	return 0;
}
