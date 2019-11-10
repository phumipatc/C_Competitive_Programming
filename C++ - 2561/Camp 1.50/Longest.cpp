/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int dp[1010][1010][4];    //l = 0,r = 1,u = 2,d = 3
int main(){
    int q,n,m,maxx;
    cin >> q;
    while(q--){
        cin >> n >> m;
        maxx = -1e9;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> a[i][j];
                if(a[i][j] == '1')
                    dp[i][j][0] = dp[i][j-1][0]+1;
            }
            for(int j=m;j>=1;j--){
                if(a[i][j] == '1')
                    dp[i][j][1] = dp[i][j+1][1]+1;
            }
        }
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++){
                if(a[i][j] == '1')
                    dp[i][j][2] = dp[i-1][j][2]+1;
            }
            for(int i=n;i>=1;i--){
                if(a[i][j] == '1')
                    dp[i][j][3] = dp[i+1][j][3]+1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                maxx = max(maxx,dp[i][j][0]-1+max(dp[i][j][2],dp[i][j][3]));
                maxx = max(maxx,dp[i][j][1]-1+max(dp[i][j][2],dp[i][j][3]));
            }
        }
        printf("%d\n",maxx);
        memset(dp,0,sizeof dp);
    }
	return 0;
}
