/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000003
using namespace std;
int dp[100001],coin[6]={1,5,10,25,50};
int main(){
    int q;
    scanf("%d",&q);
    dp[0]=1;
    for(int i=0;i<5;i++){
        for(int j=coin[i];j<=100000;j++){
            dp[j]+=dp[j-coin[i]];
            dp[j]%=MOD;
        }
    }
    int n;
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
