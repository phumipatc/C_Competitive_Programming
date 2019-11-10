/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<long long > g[100010];
long long dp[100010],order[100010],idx = 1;
void dfs(long long now){
    dp[now] = now;
    for(auto x:g[now]){
        dfs(x);
        dp[now] = max(dp[now],dp[x]);
    }
}
void post(long long now){
    for(auto x:g[now]){
        post(x);
    }
    order[idx++] = now;
}
bool cmp(long long a,long long b){
    return dp[a]<dp[b];
}
int main(){
    long long n,m,temp,st,now = 0;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&temp);
        if(temp == 0){
            st = i;
            continue;
        }
        g[temp].push_back(i);
    }
    dfs(st);
    for(long long i=1;i<=n;i++)
        sort(g[i].begin(),g[i].end(),cmp);
    post(st);
    for(long long i=1;i<=n;i++)
        order[i]+=order[i-1];
    long long opr,k;
    while(m--){
        scanf("%lld",&opr);
        if(opr == 1){
            scanf("%lld",&k);
            now+=k;
            printf("%lld\n",order[now]-order[now-1]);
        }else if(opr == 2){
            scanf("%lld",&k);
            now-=k;
        }else{
            printf("%lld\n",order[now]);
        }
    }
	return 0;
}
