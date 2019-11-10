/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int row[15],col[15],dp[15][15],cut[15][15];
int matrix_chain(int l,int r){
    if(dp[l][r]!=-1)    return dp[l][r];
    if(l == r)          return dp[l][r] = 0;
    int now;
    for(int k=l;k<r;k++){
        now = matrix_chain(l,k)+matrix_chain(k+1,r)+(row[l]*col[k]*col[r]);
        if(dp[l][r]>now || dp[l][r]==-1){
            dp[l][r] = now;
            cut[l][r] = k;
        }
    }
    return dp[l][r];
}
void print(int l,int r){
    if(l==r){
        printf("A%d",l);
        return ;
    }
    printf("(");
    print(l,cut[l][r]);
    printf(" x ");
    print(cut[l][r]+1,r);
    printf(")");
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&row[i],&col[i]);
    memset(dp,-1,sizeof dp);
    printf("%d\n",matrix_chain(1,n));
    print(1,n);
    return 0;
}
