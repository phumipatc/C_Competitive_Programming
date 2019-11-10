/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int d,m,f;
};
A Q[11];
char str[5];
int dp[12][12][12];
int main(){
    int q,n,len;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
        scanf("%d-%d-%d",&Q[i].d,&Q[i].m,&Q[i].f);
    scanf("%d",&n);
    dp[0][0][0]=1;
    while(n--){
        scanf(" %s",str);
        len=strlen(str);
        for(int i=10;i>=0;i--){
            for(int j=10;j>=0;j--){
                for(int k=10;k>=0;k--){
                    for(int l=0;l<len;l++){
                        if(str[l]=='D' && i!=0 && dp[i-1][j][k])
                            dp[i][j][k]=1;
                        if(str[l]=='M' && j!=0 && dp[i][j-1][k])
                            dp[i][j][k]=1;
                        if(str[l]=='F' && k!=0 && dp[i][j][k-1])
                            dp[i][j][k]=1;
                    }
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        if(dp[Q[i].d][Q[i].m][Q[i].f])  printf("Yes\n");
        else                            printf("No\n");
    }
    return 0;
}
