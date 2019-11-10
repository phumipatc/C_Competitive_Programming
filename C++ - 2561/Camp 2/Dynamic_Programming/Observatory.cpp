/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[2010][2010],l[2010][2010],r[2010][2010],dp[2010][2010],qs[2010][2010];
int main(){
    int n,m,k,ans = -1e9;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            l[i][j] = a[i][j]+l[i][j-1];
            qs[i][j] = a[i][j]+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i<k || j<k){
                dp[i][j] = l[i][j]+dp[i-1][j-1];
            }else{
                dp[i][j] = l[i][j]+dp[i-1][j-1];
                ans = max(ans,dp[i][j]-(qs[i][j-k]-qs[i-k][j-k])-dp[i-k][j-k]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            r[i][j] = a[i][j]+r[i][j+1];
            qs[i][j] = a[i][j]+qs[i-1][j]+qs[i][j+1]-qs[i-1][j+1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(i<k || j>m-k+1){
                dp[i][j] = r[i][j]+dp[i-1][j+1];
            }else{
                dp[i][j] = r[i][j]+dp[i-1][j+1];
                ans = max(ans,dp[i][j]-(qs[i][j+k]-qs[i-k][j+k])-dp[i-k][j+k]);
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}
/*
6 7 4
-99 -99 -99 -99 -99 -99 -99
-99 -5 -99 -99 -99 -99 -99
-99 -5 -5 -99 -99 -99 -4
-99 -5 -5 -5 -99 -5 -6
-99 -5 -5 -5 -2 -5 -6
-99 -99 -99 -5 -5 -5 -4
*/
