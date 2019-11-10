/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1000100],coin[12];
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&coin[i]);
    for(i=1;i<=m;i++)
        dp[i]=2000000000;
    for(i=1;i<=m;i++){
        for(j=0;j<n;j++){
            if(i>=coin[j])
                dp[i]=min(dp[i],dp[i-coin[j]]+1);
        }
    }
    if(dp[m]==2000000000)   printf("0\n");
    else                    printf("%d\n",dp[m]);
    return 0;
}
