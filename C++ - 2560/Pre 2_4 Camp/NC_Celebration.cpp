/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<long long > g[10005];
long long val[10005];
long long dp[10005][5];
void dfs(long long now,long long last){
    long long nextt,ch=1,dif=1e15,minn=1e15;
    for(long long i=0;i<g[now].size();i++){
        if(g[now][i]!=last){
            ch=0;
            dfs(g[now][i],now);
        }
    }
    if(ch){
        dp[now][1]=0;
        dp[now][2]=1e15;
        dp[now][3]=val[now];
        return ;
    }
    ch=1;
    for(long long i=0;i<g[now].size();i++){
        nextt=g[now][i];
        if(nextt==last) continue;
        dp[now][1]+=dp[nextt][2];
        dp[now][2]+=min(dp[nextt][2],dp[nextt][3]);
        dp[now][3]+=min(dp[nextt][1],min(dp[nextt][2],dp[nextt][3]));
        if(dp[nextt][3]>dp[nextt][2])
            dif=min(dif,dp[nextt][3]-dp[nextt][2]);
        minn=min(minn,val[nextt]);
        if(dp[nextt][2]>=dp[nextt][3])
            ch=0;
    }
    dp[now][3]+=val[now];
    if(ch)
        dp[now][2]+=min(dif,minn);
}
int main(){
    long long n,u,v;
    cin >> n;
    for(long long i=1;i<=n;i++)
        cin >> val[i];
    for(long long i=1;i<n;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,1);
    cout << min(dp[1][2],dp[1][3]);
    return 0;
}
