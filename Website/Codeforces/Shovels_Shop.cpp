/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010],offer[2010],dp[2010];
int main(){
    int n,m,k,u,v,fshovel;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        if(u<=k)    offer[u] = max(offer[u],v);
    }
    for(int i=1;i<=k;i++)
        a[i]+=a[i-1];
    for(int i=1;i<=k;i++){
        dp[i] = 1e9;
        for(int j=i;j>=1;j--){
            fshovel = 0;
            if(offer[i-j+1])    fshovel = a[j+offer[i-j+1]-1]-a[j-1];
            dp[i] = min(dp[i],a[i]-a[j-1]-fshovel+dp[j-1]);
        }
    }
    printf("%d\n",dp[k]);
	return 0;
}
