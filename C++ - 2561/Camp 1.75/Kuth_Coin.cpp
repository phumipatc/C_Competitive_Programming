/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000003
using namespace std;
int dp[100010],c[5] = {1,5,10,25,50};
int main(){
    dp[0] = 1;
    for(int i=0;i<5;i++)
        for(int j=c[i];j<=100000;j++)
            dp[j] = (dp[j] + dp[j-c[i]])%MOD;
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
	return 0;
}
