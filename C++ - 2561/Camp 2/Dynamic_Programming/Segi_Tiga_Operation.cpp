/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[260];
int dp[260][260][3],mark[260][260],n;
void segi(int l,int r){
    if(dp[1][n][0])    return ;
    if(l==r)            return ;
    if(mark[l][r])      return ;
    mark[l][r]=1;
    for(int k=l;k<r;k++){
        segi(l,k);
        segi(k+1,r);
        for(int ch1=0;ch1<3;ch1++){
            for(int ch2=0;ch2<3;ch2++){
                if(dp[l][k][ch1]!=1 || dp[k+1][r][ch2]!=1)    continue;
                if(ch1==0){
                    if(ch2==0)  dp[l][r][2]=1;
                    if(ch2==1)  dp[l][r][1]=1;
                    if(ch2==2)  dp[l][r][0]=1;
                }
                if(ch1==1){
                    if(ch2==0)  dp[l][r][2]=1;
                    if(ch2==1)  dp[l][r][1]=1;
                    if(ch2==2)  dp[l][r][1]=1;
                }
                if(ch1==2){
                    if(ch2==0)  dp[l][r][1]=1;
                    if(ch2==1)  dp[l][r][2]=1;
                    if(ch2==2)  dp[l][r][1]=1;
                }
                if(dp[1][n][0])
                    return ;
            }
        }
    }
}
int main(){
    int q=20;
    while(q--){
        scanf("%d %s",&n,str+1);
        for(int i=1;i<=n;i++)
            mark[i][i] = 1,dp[i][i][str[i]-'0']=1;
        segi(1,n);
        if(dp[1][n][0])    printf("yes\n");
        else                printf("no\n");
        memset(dp,0,sizeof dp);
        memset(mark,0,sizeof mark);
    }
    return 0;
}
