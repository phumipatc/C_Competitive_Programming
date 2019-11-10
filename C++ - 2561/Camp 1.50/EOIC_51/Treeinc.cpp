/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[300100];
int dp[300100];
int main(){
    int n,maxx = -1e9,u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        if(u<v) swap(u,v);
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        for(auto &j:g[i])
            dp[i] = max(dp[i],dp[j]);
        dp[i]++;
        maxx = max(maxx,dp[i]);
    }
    printf("%d\n",maxx);
	return 0;
}
