/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int main()
{
    int n,m,i,j,k,p,r,c,minn,maxx,q=2,t,s;
    while(q--)
    {
        maxx=-1;
        scanf("%d %d %d",&n,&m,&p);
        for(i=1; i<=p; i++)
        {
            scanf("%d %d",&r,&c);
            dp[r+1][c+1]=1;
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                dp[i][j]+=dp[i-1][j];
            }
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                dp[i][j]+=dp[i][j-1];
            }
        }
        minn=min(n,m);
        for(k=1; k<=minn; k++)
        {
            for(i=1; i<=n-k+1; i++)
            {
                for(j=1; j<=m-k+1; j++)
                {
                    t=dp[i+k-1][j+k-1]-dp[i+k-1][j-1]-dp[i-1][j+k-1]+dp[i-1][j-1];
                    s=dp[i+k-2][j+k-2]-dp[i+k-2][j]-dp[i][j+k-2]+dp[i][j];
                    if(t-s==0)
                    {
                        maxx=k;
                    }
                }
            }
        }
        printf("%d\n",maxx);
        memset(dp,0,sizeof dp);
    }
    return 0;
}
/*
5 8
6
0 7
1 3
2 0
3 6
4 2
4 5
5 5
8
0 0
0 4
4 0
4 4
0 1
2 0
2 4
4 3
*/
