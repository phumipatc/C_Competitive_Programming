/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110],dp[110][110];
int main(){
    int q,n,k;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=k;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++)
                dp[i][j] = 1e9;
        for(int i=1;i<=k;i++){
            if(a[i] == -1)  continue;
            for(int j=0;j<n;j++){
                for(int l=0;l<k;l++){
                    if(dp[j][l] == 1e9) continue;
                    if(l+i>k)           break;
                    dp[j+1][l+i] = min(dp[j][l]+a[i],dp[j+1][l+i]);
                }
            }
        }
        if(dp[n][k] == 1e9) printf("-1\n");
        else                printf("%d\n",dp[n][k]);
    }
    return 0;
}
