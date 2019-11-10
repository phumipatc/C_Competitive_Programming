/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
queue<int > que;
vector<int > g[300010];
int in[300010],dp[300010];
int main(){
    int n,u,v,st1,st2;
    scanf("%d %d %d",&n,&st1,&st2);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++;
        in[v]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i]>1)     continue;
        if(i == st1)    continue;
        if(i == st2)    continue;
        dp[i] = 1;
        que.push(i);
    }
    while(!que.empty()){
        int now = que.front();
        que.pop();
        if(now == st1 || now == st2)    continue;
        for(auto x:g[now]){
            in[x]--;
            if(in[x] == 0)  continue;
            dp[x]+=dp[now];
            if(in[x] == 1)  que.push(x);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(!in[i])  continue;
        ans = max(ans,dp[i]);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",dp[i]);
    printf("\n%d\n",ans);
    return 0;
}