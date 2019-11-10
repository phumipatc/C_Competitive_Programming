/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010],key[2010];
int dp[1010][1010];
int main(){
    int k;
    scanf(" %s %s %d",a+1,b+1,&k);
    int lena = strlen(a+1);
    int lenb = strlen(b+1);
    while(k--){
        scanf(" %s",key+1);
        dp[0][0] = 1;
        for(int i=0;i<=lena;i++){
            for(int j=0;j<=lenb;j++){
                if(i!=0 && dp[i-1][j] && a[i] == key[i+j])  dp[i][j] = 1;
                if(j!=0 && dp[i][j-1] && b[j] == key[i+j])  dp[i][j] = 1;
            }
        }
        if(dp[lena][lenb])  printf("Yes\n");
        else                printf("No\n");
        memset(dp,0,sizeof dp);
    }
    return 0;
}
