#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N][27];
int mark[27][27];
char str[N];
int main()
{
    scanf(" %s",str+1);
    int q,len=strlen(str+1);
    char a,b;
    scanf("%d",&q);
    while(q--){
        scanf(" %c %c",&a,&b);
        mark[a-'a'+1][b-'a'+1] = mark[b-'a'+1][a-'a'+1] = 1;
    }
    memset(dp,127,sizeof dp);
    dp[0][0] = 0;
    for(int i=1;i<=len;i++){
        int now = 1e9;
        for(int j = 0;j<=26;j++)
            if(!mark[j][str[i]-'a'+1])
                now = min(now,dp[i-1][j]);
        for(int j=0;j<=26;j++)
            dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
        dp[i][str[i]-'a'+1] = min(dp[i][str[i]-'a'+1],now);
    }
    int mi = 1e9;
    for(int i=0;i<=26;i++){
        mi = min(mi,dp[len][i]);
    }
    printf("%d\n",mi);
    return 0;
}
