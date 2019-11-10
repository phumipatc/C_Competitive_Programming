/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[600][600];
int dp[10][600][600],qs[600][600];
int ans(int si,int sj,int ei,int ej,int sizee){
    if(dp[sizee][si][sj]!=-1) return dp[sizee][si][sj];
    if(sizee == 0)            return 0;
    int minn = 1e9,mi = (ei+si)/2,mj = (ej+sj)/2,all = ((ei-si+1)*(ej-sj+1))/4;
    int sum1 = qs[mi][mj]-qs[si-1][mj]-qs[mi][sj-1]+qs[si-1][sj-1];
    int sum2 = qs[mi][ej]-qs[si-1][ej]-qs[mi][mj]+qs[si-1][mj];
    int sum3 = qs[ei][mj]-qs[mi][mj]-qs[ei][sj-1]+qs[mi][sj-1];
    int sum4 = qs[ei][ej]+qs[mi][mj]-qs[ei][mj]-qs[mi][ej];
    //up-left
    minn = min(minn,ans(mi+1,sj,ei,mj,sizee-1)+ans(mi+1,mj+1,ei,ej,sizee-1)+sum1+(all-sum2));
    minn = min(minn,ans(si,mj+1,mi,ej,sizee-1)+ans(mi+1,mj+1,ei,ej,sizee-1)+sum1+(all-sum3));
    minn = min(minn,ans(si,mj+1,mi,ej,sizee-1)+ans(mi+1,sj,ei,mj,sizee-1)+sum1+(all-sum4));
    //up-right
    minn = min(minn,ans(mi+1,sj,ei,mj,sizee-1)+ans(mi+1,mj+1,ei,ej,sizee-1)+sum2+(all-sum1));
    minn = min(minn,ans(si,sj,mi,mj,sizee-1)+ans(mi+1,mj+1,ei,ej,sizee-1)+sum2+(all-sum3));
    minn = min(minn,ans(si,sj,mi,mj,sizee-1)+ans(mi+1,sj,ei,mj,sizee-1)+sum2+(all-sum4));
    //down-left
    minn = min(minn,ans(si,mj+1,mi,ej,sizee-1)+ans(mi+1,mj+1,ei,ej,sizee-1)+sum3+(all-sum1));
    minn = min(minn,ans(si,sj,mi,mj,sizee-1)+ans(mi+1,mj+1,ei,ej,sizee-1)+sum3+(all-sum2));
    minn = min(minn,ans(si,sj,mi,mj,sizee-1)+ans(si,mj+1,mi,ej,sizee-1)+sum3+(all-sum4));
    //down-right
    minn = min(minn,ans(si,mj+1,mi,ej,sizee-1)+ans(mi+1,sj,ei,mj,sizee-1)+sum4+(all-sum1));
    minn = min(minn,ans(si,sj,mi,mj,sizee-1)+ans(mi+1,sj,ei,mj,sizee-1)+sum4+(all-sum2));
    minn = min(minn,ans(si,sj,mi,mj,sizee-1)+ans(si,mj+1,mi,ej,sizee-1)+sum4+(all-sum3));
    return dp[sizee][si][sj]=minn;
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf(" %s",a[i]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            qs[i][j]=(a[i][j]-'0')+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
    memset(dp,-1,sizeof dp);
    printf("%d\n",ans(1,1,n,n,log2(n)));
    return 0;
}
