/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<long long > g[100010];
long long deg[100010],val[100010][4];
long long num[3],used[4],ans[100010];
long long col,minn = 1e18;
long long dfs(long long now,long long p){
    long long ret = val[now][num[col]];
    for(auto x:g[now]){
        if(x == p)  continue;
        col++,col%=3;
        return ret+dfs(x,now);
    }
    return ret;
}
void dfs2(long long now,long long p){
    ans[now] = num[col];
    for(auto x:g[now]){
        if(x == p)  continue;
        col++,col%=3;
        dfs2(x,now);
        return ;
    }
}
void permute(long long state,long long st){
    if(state == 3){
        col = 0;
        long long ret = dfs(st,0);
        if(minn>ret){
            minn = ret;
            col = 0;
            dfs2(st,0);
            // for(long long i=0;i<3;i++)
            //     printf("%lld ",ans[i]);
            // printf("\n");
        }
        return ;
    }
    for(long long i=1;i<=3;i++){
        if(used[i]) continue;
        num[state] = i;
        used[i] = 1;
        permute(state+1,st);
        used[i] = 0;
    }    
}
int main(){
    long long n,u,v;
    scanf("%lld",&n);
    for(long long i=1;i<=3;i++)
        for(long long j=1;j<=n;j++)
            scanf("%lld",&val[j][i]);
    for(long long i=1;i<n;i++){
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    for(long long i=1;i<=n;i++){
        if(deg[i]<=2)   continue;
        printf("-1\n");
        return 0;
    }
    for(long long i=1;i<=n;i++){
        if(deg[i]>1)    continue;
        permute(0,i);
        break;
    }
    printf("%lld\n",minn);
    for(long long i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    return 0;
}