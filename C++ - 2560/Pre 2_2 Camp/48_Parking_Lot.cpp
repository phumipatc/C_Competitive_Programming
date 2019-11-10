/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en;
    bool operator < (const A&o) const{
        if(en!=o.en)    return en<o.en;
        else            return st>o.st;
    }
};
A a[310];
int dp[310][310];
int main(){
    int q,n,i,j,k;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d %d",&a[i].st,&a[i].en);
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++){
            dp[i][i]=1;
            for(j=0;j<i;j++)
                if(a[j].st>=a[i].st)
                    dp[i][i]=max(dp[i][i],dp[j][i]+1);
            for(j=1;j<=n;j++){
                dp[i][j]=dp[i][i];
                if(a[j].st>a[i].st) continue;
                for(k=0;k<i;k++)
                    if(a[k].en<=a[i].st && a[k].st>=a[j].st)
                        dp[i][j]=max(dp[i][j],dp[i][i]+dp[k][j]);
            }
        }
        int maxx=-1;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                maxx=max(maxx,dp[i][j]);
        printf("%d\n",maxx);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
