/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[10010];
int mark[10010];
int dfs(int now){
    mark[now]=1;
    int maxx=-1,maxn=-1;
    for(int i=0;i<g[now].size();i++){
        if(mark[g[now][i]]) continue;
        int x=dfs(g[now][i]);
        if(x>maxx)
            maxn=maxx,maxx=x;
        else
            maxn=max(maxn,x);
    }
    if(maxx==-1 || maxn==-1) return 1;
    else                      return maxx+maxn+1;
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int minn=1e9,n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)   g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            memset(mark,0,sizeof mark);
            int ans;
            ans=dfs(i);
            minn=min(minn,n-ans);
        }
        printf("%d\n",minn);
    }
    return 0;
}
/*
3
3
2 1
1 3
7
4 5
4 2
1 2
3 1
6 4
3 7
4
1 2
2 3
3 4
*/
