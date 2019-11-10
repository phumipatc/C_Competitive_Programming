/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[10];
char a[5];
int main(){
    int n,v;
    scanf("%d",&n);
    for(int i=1;i<=7;i++)
        dp[i] = 1e9;
    for(int i=1;i<=n;i++){
        scanf("%d %s",&v,a+1);
        int len = strlen(a+1),num = 0;
        for(int i=1;i<=len;i++)
            num|=(1<<(a[i]-'A'));
        for(int i=0;i<=7;i++)
            dp[i|num] = min(dp[i|num],dp[i]+v);
    }
    if(dp[7] == 1e9)    printf("-1\n");
    else                printf("%d\n",dp[7]);
	return 0;
}