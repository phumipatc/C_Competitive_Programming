/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[100010][4][4][4][4],a[100010];
char str[100010];
int diff(int a,int b,int c){
    int sum = 0;
    if(a == 1 || b == 1 || c == 1)  sum++;
    if(a == 2 || b == 2 || c == 2)  sum++;
    if(a == 3 || b == 3 || c == 3)  sum++;
    return sum;
}
int main(){
    int n;
    scanf("%d %s",&n,str+1);
    for(int i=1;i<=n;i++){
        if(str[i] == 'M')       a[i] = 1;
        else if(str[i] == 'F')  a[i] = 2;
        else if(str[i] == 'B')  a[i] = 3;
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                for(int l=0;l<4;l++)
                    for(int m=0;m<4;m++)
                        dp[i][j][k][l][m] = -1<<30;
    dp[1][0][a[1]][0][0] = dp[1][0][0][0][a[1]] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    for(int m=0;m<4;m++){
                        dp[i][k][a[i]][l][m] = max(dp[i][k][a[i]][l][m],dp[i-1][j][k][l][m]+diff(j,k,a[i]));
                        dp[i][j][k][m][a[i]] = max(dp[i][j][k][m][a[i]],dp[i-1][j][k][l][m]+diff(l,m,a[i]));
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int j=0;j<4;j++){
        for(int k=0;k<4;k++){
            for(int l=0;l<4;l++){
                for(int m=0;m<4;m++){
                    ans = max(ans,dp[n][j][k][l][m]);
                }
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}
