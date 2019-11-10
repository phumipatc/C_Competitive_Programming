/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000010];
int main(){
    int q,n,i;
    scanf("%d",&q);
    for(i=2;i<=1000000;i++){
        dp[i] = dp[i-1]+1;
        if(i%2 == 0 && dp[i/2]+1<dp[i])
            dp[i] = dp[i/2]+1;
        if(i%3 == 0 && dp[i/3]+1<dp[i])
            dp[i] = dp[i/3]+1;
    }
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
