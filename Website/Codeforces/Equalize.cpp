/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000010],b[1000010];
int dp[1000010];
int main(){
    int n,idx0,idx1;
    scanf("%d %s %s",&n,a+1,b+1);
    idx0 = idx1 = 0;
    for(int i=1;i<=n;i++){
        if(a[i] == b[i]){
            dp[i] = dp[i-1];
            continue;
        }
        if(a[i] == '0'){
            idx0 = i;
            if(idx1 == 0){
                dp[i] = dp[i-1]+1;
                continue;
            }
            dp[i] = min(dp[i-1]+1,dp[i-1]-dp[idx1]+dp[idx1-1]+(i-idx1));
        }else{
            idx1 = i;
            if(idx0 == 0){
                dp[i] = dp[i-1]+1;
                continue;
            }
            dp[i] = min(dp[i-1]+1,dp[i-1]-dp[idx0]+dp[idx0-1]+(i-idx0));
        }
    }
    printf("%d\n",dp[n]);
	return 0;
}