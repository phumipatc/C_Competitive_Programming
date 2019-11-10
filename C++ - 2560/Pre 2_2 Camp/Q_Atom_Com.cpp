/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long dp[30][2100000];
int main(){
    long long q,num,bit,zero=(1<<20)-1;
    dp[1][zero-1]=dp[1][zero]=dp[1][zero+1]=1;
    for(long long i=2;i<=20;i++){
        for(long long j=0;j<=2*zero;j++){
            if(j-(1<<(i-1))>=0)         dp[i][j]+=dp[i-1][j-(1<<(i-1))];
            dp[i][j]+=dp[i-1][j];
            if(j+(1<<(i-1))<=zero*2)    dp[i][j]+=dp[i-1][j+(1<<(i-1))];
        }
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&num,&bit);
        if(abs(num)>=1<<20)    printf("0");
        else
            printf("%lld\n",dp[bit][zero+num]);
    }
    return 0;
}
