/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long best(long long n,long long k){
    k++;
    return k*(n/k)*((n/k)+1)/2 + (n%k)*((n/k)+1);
}
long long dp[110][510],countt[110];
int main(){
    int n,m,k,kk,num;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&num),countt[num]++;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = 1e18;
            for(int kk=0;kk<=j;kk++){
                dp[i][j] = min(dp[i][j],best(countt[i],kk)+dp[i-1][j-kk]);
            }
        }
    }
    printf("%lld\n",dp[m][k]);
    return 0;
}
