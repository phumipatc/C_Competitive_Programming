/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[50][50][50][50],a[50][50],qm[50][50][50][50];
long long cake(long long sti,long long stj,long long eni,long long enj){
    if(dp[sti][stj][eni][enj]!=-1)      return dp[sti][stj][eni][enj];
    else if(sti == eni && stj == enj)   return 0;
    long long minn = 1e18;
    for(long long k=sti;k<eni;k++){
        minn = min(minn,cake(sti,stj,k,enj)+cake(k+1,stj,eni,enj)+(qm[sti][stj][k][enj]+qm[k+1][stj][eni][enj]));
    }
    for(long long k=stj;k<enj;k++){
        minn = min(minn,cake(sti,stj,eni,k)+cake(sti,k+1,eni,enj)+(qm[sti][stj][eni][k]+qm[sti][k+1][eni][enj]));
    }
//    printf("%lld %lld %lld %lld %lld\n",sti,stj,eni,enj,minn);
    return dp[sti][stj][eni][enj] = minn;
}
int main(){
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=m;j++)
            scanf("%lld",&a[i][j]);
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=m;j++)
            for(long long k=1;k<=n;k++)
                for(long long l=1;l<=m;l++)
                    qm[i][j][k][l] = 1;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            for(long long k=i;k<=n;k++){
                for(long long l=j;l<=m;l++){
                    for(long long ni=i;ni<=k;ni++){
                        for(long long nj=j;nj<=l;nj++){
                            qm[i][j][k][l]*=a[ni][nj];
                        }
                    }
                }
            }
        }
    }
    memset(dp,-1,sizeof dp);
    printf("%lld\n",cake(1,1,n,m));
    return 0;
}
