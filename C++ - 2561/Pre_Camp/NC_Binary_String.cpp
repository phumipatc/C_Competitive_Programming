/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
char str[100100];
int mark[21][1<<20],dp[100100];
int main(){
    int n,sum,len;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",str+1);
        sum = 0;
        len = strlen(str+1);
        for(int j=1;j<=len;j++)
            sum = (str[j]-'0')+(sum*2);
        mark[len][sum] = 1;
    }
    scanf(" %s",str+1);
    len = strlen(str+1);
    dp[0] = 1;
    for(int i=1;i<=len;i++){
        sum = 0;
        for(int j = i;j>0 && i-j<20;j--){
            sum+=(str[j]-'0') * (1<<(i-j));
            if(mark[i-j+1][sum])    dp[i]+=dp[j-1],dp[i]%=MOD;
        }
    }
    printf("%d\n",dp[len]);
    return 0;
}
