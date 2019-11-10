/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[100001];
long long mark[100001],v[100001];
void dfs(long long now){
    if(mark[now]==1)    return ;
    mark[now]=1;
    for(long long i=0;i<g[now].size();i++){
        if(!mark[g[now][i]]){
            dfs(g[now][i]);
            v[now]+=v[g[now][i]];
        }
    }
}
int main(){
    long long q,n,a,b;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(long long i=1;i<n;i++){
            scanf("%lld %lld",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(long long i=1;i<=n;i++)
            scanf("%lld",&v[i]);
        dfs(1);
        long long ans=1e18;
        for(long long i=1;i<=n;i++)
            ans=min(ans,abs(v[1]-(2*v[i])));
        printf("%lld\n",ans);
        for(long long i=1;i<=n;i++)   g[i].clear();
        memset(mark,0,sizeof mark);
        memset(v,0,sizeof v);
    }
    return 0;
}
/*
2 6
1 2
1 3
1 5
5 6
6 4
2 1 3 3 4 6
*/
