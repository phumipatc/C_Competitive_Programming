/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100010],temp[100010];
int main(){
    int q,n,k,num;
    scanf("%d",&q);
    for(int x=1;x<=q;x++){
        scanf("%d %d",&n,&k);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            scanf("%d",&num);
            for(int j=0;j<=k;j++)
                if(dp[j])
                    temp[(j+num)%k] = 1;
            for(int j=1;j<=k;j++)
                if(temp[j])
                    dp[j] = 1,temp[j] = 0;
        }
        for(int i=k-1;i>=0;i--){
            if(dp[i]){
                printf("Case #%d: %d\n",x,i);
                break;
            }
        }
        memset(dp,0,sizeof dp);
    }
    return 0;
}
