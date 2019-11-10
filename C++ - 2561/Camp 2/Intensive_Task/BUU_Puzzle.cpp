/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[7][50010],dp[50010][40];
int main(){
    int q,n,sum,ans;
    scanf("%d",&q);
    while(q--){
        ans = 0;
        scanf("%d",&n);
        for(int i=0;i<5;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(int j=0;j<n;j++){
            for(int i=0;i<32;i++){
                if((i&1 && i&2) || (i&2 && i&4) || (i&4 && i&8) || (i&8 && i&16))   continue;
                sum = 0;
                for(int k=0;k<5;k++){
                    if(i&(1<<k)){
                        sum+=a[k][j];
                    }
                }
                for(int k=0;k<32 && j>0;k++){
                    if(i&k) continue;
                    dp[j][i] = max(dp[j][i],dp[j-1][k]);
                }
                dp[j][i]+=sum;
            }
        }
        for(int i=0;i<32;i++){
            ans = max(ans,dp[n-1][i]);
        }
        printf("%d\n",ans);
        memset(dp,0,sizeof dp);
    }
	return 0;
}
/*
2
6
1 0 0 0 0 0
0 1 1 10 1 0
1 10 0 0 5 10
0 1 1 10 0 0
1 0 0 0 1 10
*/