/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100100],coin[10]={1,5,10,25,50};
int main()
{
    int q,i,j,num;
    scanf("%d",&q);
    dp[0]=1;
    for(i=0;i<5;i++){
        for(j=coin[i];j<=100000;j++){
            dp[j]+=dp[j-coin[i]];
            dp[j]%=1000003;
        }
    }
    while(q--){
        scanf("%d",&num);
        printf("%d\n",dp[num]);
    }
    return 0;
}
