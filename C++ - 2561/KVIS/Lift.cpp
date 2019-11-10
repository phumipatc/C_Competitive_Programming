/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[45010];
int main(){
    int n,num,sum = 0,minn = 1e9,ans1,ans2;
    scanf("%d",&n);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        sum+=num;
        for(int j=45000;j>=num;j--){
            if(dp[j-num])
                dp[j] = 1;
        }
    }
    for(int i=0;i<=sum;i++){
        if(dp[i]){
            if(abs(sum-(2*i))<minn){
                minn = abs(sum-(2*i));
                ans1 = i;
                ans2 = sum-i;
            }
        }
    }
    if(ans1>ans2)   swap(ans1,ans2);
    printf("%d %d\n",ans1,ans2);
    return 0;
}
