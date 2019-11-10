/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110],dp[110][110],change[110][110];
int bead(int l,int r){
    if(l==r)        return dp[l][r]=0;
    if(dp[l][r]!=1<<30)    return dp[l][r];
    int k,minn,now;
    for(k=l,minn=1e9;k<r;k++){
        now=bead(l,k)+bead(k+1,r)+(change[l][k]*change[k+1][r]);
//        printf("%d\n",bead(l,k));
        if(now < dp[l][r]){
            dp[l][r] = now;
            change[l][r]=(change[l][k]+change[k+1][r])%100;
        }
    }
    return dp[l][r];
}
int main()
{
    int q,n,i,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)   scanf("%d",&a[i]);
        for(i=1;i<=n;i++)   change[i][i]=a[i];
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dp[i][j] = 1<<30;
        printf("%d\n",bead(1,n));
    }
    return 0;
}
