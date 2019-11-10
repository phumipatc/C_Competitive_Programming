/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
char a[510][510];
int dp[510][510];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf(" %c",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = 1e9;
            for(int k=1;k<=n;k++){
                if(a[k][j] == '.')  continue;
                dp[i][j] = min(dp[i][j],abs(i-k));
            }
        }
    }
    int q,sti,stj,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&sti,&stj);
        ans = 1e9;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         printf("%d ",dp[i][j]);
        //     }
        //     printf("\n");
        // }
        for(int i=1;i<=m;i++){
            if(dp[sti][i] == 1e9)   continue;
            ans = min(ans,(dp[sti][i]*dp[sti][i])+((stj-i)*(stj-i)));
        }
        printf("%d\n",ans);
        for(int k=1;k<=n;k++){
            dp[k][stj] = min(dp[k][stj],abs(k-sti));
        }
    }
	return 0;
}
/*
5 5
..x..
....x
.....
.....
.....
*/