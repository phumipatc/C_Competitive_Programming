/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long now,w;
};
struct B{
    long long u,v;
};
A now;
B a[100005];
queue <A > que;
vector <A > g[100100];
long long in[100100],dp[100100],mark[100100];
int main(){
    long long n,m,i,j,sum;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%lld %lld",&a[i].u,&a[i].v);
        in[a[i].u]++,in[a[i].v]++;
        g[a[i].u].push_back({a[i].v,0});
        g[a[i].v].push_back({a[i].u,0});
    }
    for(i=1;i<=n;i++){
        dp[i] = 1;
        if(in[i] == 1)
            que.push({i,1});
    }
    while(!que.empty()){
        now = que.front();
        que.pop();
        mark[now.now] = 1;
        for(long long i=0;i<g[now.now].size();i++){
            in[g[now.now][i].now]--;
            if(in[g[now.now][i].now]>0){
                dp[g[now.now][i].now]+=now.w;
            }
            if(in[g[now.now][i].now] == 1){
                que.push({g[now.now][i].now,dp[g[now.now][i].now]});
            }
        }
    }
    for(long long i=1;i<=m;i++){
        if(!mark[a[i].u] && !mark[a[i].v])  printf("0 ");
        else                                printf("%lld ",min(dp[a[i].u],dp[a[i].v])*(n-min(dp[a[i].u],dp[a[i].v])));
    }
    return 0;
}
/*
6 6
1 2
1 3
1 4
2 3
2 5
3 6
*/
